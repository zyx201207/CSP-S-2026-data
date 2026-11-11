# include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long num=0;
int n;
long long a[N];
char c[N];
long long pre_a[N];
long long ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        num+=a[i];
        pre_a[i]=pre_a[i-1]+a[i];
    }
    //s[i]==s[num+1-i]
    long long p=1;
    long long j=n,i=1;
    long long op=0;
    long long l=num+1-pre_a[i],r=num+1-p;//c[i]
    long long L=pre_a[j-1]+1,R=pre_a[j];//c[j]
    while(i<=j){
        if(L==l){
            if(c[i]!=c[j]){
                ans+=r-l+1;
            }
            p=pre_a[i]+1;j--;i++;
            l=num+1-pre_a[i],r=num+1-p;
            L=pre_a[j-1]+1,R=pre_a[j];
        }else if(L>l){
              if(c[i]!=c[j]){
                ans+=R-L+1;
              }
              r=L-1;
              j--;L=pre_a[j-1]+1,R=pre_a[j];
        }else if(L<l){
            if(c[i]!=c[j]){
                ans+=r-l+1;
            }
            R=l-1;
            p=pre_a[i]+1;
            i++;l=num+1-pre_a[i],r=num+1-p;
        }
    }
    cout<<ans;
    return 0;
}
