#include <bits/stdc++.h>
using namespace std;
long long n,cnt=0,t1=0,t2;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    string s1,s2;
    for(long long i=0;i<n;i++){
        long long a;
        char c;
        cin>>a>>c;
        cnt+=a;
        while(a--){
            s1[t1]=c;
            t1++;
        }
        if(i==n-1){
            t2=t1;
            long long ans=0;
            for(long long i=0;i<t1;i++){
                s2[t2-i-1]=s1[i];
            }
            for(long long i=0;i<t1;i++){
                if(s1[i]!=s2[i]) ans++;
            }
            cout<<ans/2;
        }
    }

    return 0;
}
