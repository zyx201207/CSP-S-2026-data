#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long a,z=0,n=0,q=0,p=0,q1=0,p1=0;
    cin>>a;
    long long x[a+10]={0};
    char y[a+10]={" "};
    for(int i = 1;i<=a;i++){
        cin>>x[i]>>y[i];
        z+=x[i];
    }
    q1=0;
    p1=a+1;
    for(int i = 1;i<=ceil(z/2);i++){
        if(q==0){
            q1++;
            q=x[q1];
        }
        if(p==0){
            p1--;
            p=x[p1];
        }
        if(y[q1]!=y[p1]){
            n++;
        }
        q--;
        p--;
    }
    cout<<n;
    return 0;
}
