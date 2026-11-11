#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005],L=0;
char c[200005];
long long n1[200005],n2[200005];//length 1=index  length 2=n-index+1
char c1[200005],c2[200005];
long long seg[1000005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        a[i]+=a[i-1];
    }
    long long mid=(a[n]-1)/2+1;
    int index=upper_bound(a+1,a+n+1,mid)-a;
    int C=0;
    for(int i=1;i<index;i++){
        seg[++C]=n1[i]=a[i];
        c1[i]=c[i];
    }
    n1[index]=mid;
    c1[index]=c[index];
    for(int i=n;i>index;i--){
        seg[++C]=n2[n-i+1]=a[n]-a[i-1];
        c2[n-i+1]=c[i];
    }
    n2[n-index+1]=a[n]-mid+(n%2);
    c2[n-index+1]=c[index];
    sort(seg+1,seg+C+1);
    int cseg=unique(seg+1,seg+C+1)-seg-1;
    long long ans=0;
    for(int i=1;i<=cseg;i++){
        int f1=lower_bound(n1+1,n1+index+1,seg[i])-n1;
        int f2=lower_bound(n2+1,n2+n-index+2,seg[i])-n2;
        if(c1[f1]!=c2[f2])ans+=seg[i]-seg[i-1];
    }
    cout<<ans;

    return 0;
}
