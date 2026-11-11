#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],ch[500010],ans;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){//加给第几个
        long long tmp=1,tpm=m,sum=0,anst=0;
        for(int k=1;k<=n;k++){//差
            if(a[k]<a[i]){
                ch[tmp]=a[i]-a[k];
                sum+=ch[tmp];
                tmp++;
            }
        }
        for(int j=1;j<=tmp;j++){
            if(ch[j]<=tpm){
                tpm-=ch[j];
                anst++;
            }
        }
        ans=max(ans,anst);
    }
    cout<<ans;
}
