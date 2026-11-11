#include<bits/stdc++.h>
using namespace std;
char w1='0',w2='1';
long long m,n,num,numx=-1;
long long a[200005];
string s[20000000],s1[20000000];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=0;i<n;i++){
        cin>>a[i];
        long long y=a[i];
        while(y){
            int z=y%2;
            y/=2;
            if(z) s[a[i]]+=w2;
            else s[a[i]]+=w1;
        }
    }
    for(long long i=0;i<n;i++){
        long long l1=s[a[i]].size();
        for(long long j=i+1;j<n;j++){
            string s2;
            long long l2=s[a[j]].size();
            long long l;
            if(l1>l2) l=l1;
            else l=l2;
            for(long long q=0;q<l;q++){
                if(s[a[i]][q]=='1'&&s[a[j]][q]=='1') s2[q]='1';
                else s2[q]='0';
            }
            num=0;
            for(long long q=0;q<l;q++){
                num+=pow(2,q)*s2[q];
            }
            if(num>numx) numx=num;
        }
    }
    cout<<numx;
    return 0;
}
