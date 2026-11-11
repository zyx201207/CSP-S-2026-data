#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],sum[200005],sum1=0;
char ch[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>ch[i];
        sum[i]=sum[i-1]+a[i];
    }
    long long ans=0,tmp=0,las=0;
    for(int i=1,j=n;i<=j;){
        long long st=sum[i];
        long long end=sum[n]-sum[j-1];
        //cout<<st<<" "<<end<<'\n';
        las=tmp;
        tmp=min(st,end);
        if(ch[i]!=ch[j])ans+=tmp-las;
        if(st<=end)i++;
        if(st>=end)j--;
    }
    cout<<ans;
    return 0;
}