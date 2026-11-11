#include <bits/stdc++.h>
using namespace std;
struct N{
    int m;
    char a;
}s[500001];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i].m;
        cin>>s[i].a;
    }
    int j=1,k=n;
    while(j<k){
        if(s[j].m>s[k].m){
            if(s[j].a!=s[k].a)cnt+=s[k].m;
            s[j].m-=s[k].m;
            k--;
        }else{
            if(s[j].a!=s[k].a)cnt+=s[j].m;
            s[k].m-=s[j].m;
            j++;
            if(s[k].m==0)k--;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
