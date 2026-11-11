#include<bits/stdc++.h>
using namespace std;
long long n,m[250000],sum,cnt,js,f,ff;
long long xb,size_;
string s="";
char ch[250000];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n;
    for(long long i=0;i<n;i++){
        cin>>m[i]>>ch[i];
        sum+=m[i];
    }
    f=sum/2;
    ff=(sum+1)/2;
    for(long long i=0;i<=n;i++){
        for(long long j=0;j<m[i];j++){
            s=s+ch[i];
            size_++;
            if(size_>ff){
                if(ch[i]!=s[f-(size_-ff)]){
                    cnt++;
                }
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}

