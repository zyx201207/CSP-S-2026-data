#include <bits/stdc++.h>
using namespace std;
int main(){
    //freopen("and.in","w",stdin);
    //freopen("and.out","r",stdout);
    long long n,m,maxn=0;
    int s[1000000];
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>s[i];
    }

    for(int i=0;i<n;i++){
        long long a=s[i];
        string c1,c2,c3;
        while(a!=0){
            if(a%2==1)
                c1+='1';
            else
                c1+='0';
            a/=2;
        }

        for(int j=0;j<n;j++){
            long long b=s[j],h=0;
             while(b!=0){
            if(b%2==1)
                c2+='1';
            else
                c2+='0';
            b/=2;
        }

        long long l=min(c1.size(),c2.size());
        for(long long k=0;k<l;k++){
            if(c1[k]==c2[k])
                c3+='1';
            else
                c3+='0';
        }

        for(long long o=0;o<l;o++){
            h+=pow(2,o)*(c3[o]-'0');
        }
        maxn=max(maxn,h);
        }
    }
    cout<<maxn;

return 0;
}

