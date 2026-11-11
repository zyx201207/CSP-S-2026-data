#include<bits/stdc++.h>
using namespace std;
struct node{
    long long a;
    int w;
    char c;
}s[200050];
node p[200050];
int main(){
    int n;
    s[0].a=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i].w>>s[i].c;
        s[i].a=s[i-1].a+s[i].w;
    }
    long long k=s[n].a/2;
    long long d=(s[n].a+3)/2;
    int i=1;
    for(;s[i].a<=k;i++){
        p[i].a=s[i].a;
        p[i].w=s[i].w;
        p[i].c=s[i].c;
    }
    int j=i+1;
    if(p[i-1].a<k){
        p[i].a=k;
        p[i].w=k-p[i-1].a;
        p[i].c=s[i].c;
        if(s[i].a>=d){
            p[j].a=s[i].a;
            p[j].c=s[i].c;
            p[j].w=p[j].a-d+1;
            j++;
        }
    }
    for(int g=i+1;g<=n;j++,g++){
        p[j].a=s[g].a;
        p[j].c=s[g].c;
        p[j].w=s[g].w;
    }
    long long y=s[n].a;
    int q=n;
    long long sum;
    for(int x=1;x<=i;x++){
        long long z=y-p[x].w;
        while(p[q-1].a>=z){
            if(p[q].c!=p[x].c){
                sum+=p[q].w;
            }
            q--;
        }
        if(p[q].a>z){
            if(p[q].c!=p[x].c){
                sum+=p[q].a-z;
            }
            p[q].c=p[q].c-p[q].a+z;
            p[q].a=z;
        }
        y=z;
    }
    cout<<sum;
    return 0;
}
