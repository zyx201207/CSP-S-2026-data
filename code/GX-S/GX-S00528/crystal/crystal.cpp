#include <bits/stdc++.h>
const int maxn=500500;
using namespace std;
long long n,m,a[maxn],qz[maxn];
long long ans,nmax,l,r,um,omid,mid;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)qz[i]=(a[i]+qz[i-1]);
    l=1,r=n;mid=(l+r)/2;
    while(omid!=mid){
        um=(mid*a[mid]-qz[mid]);
        if(um>m){
            r=mid;
        }else if(mid==1){
            break;
        }else{
            ans=max(ans,mid);
            l=mid;
        }
        omid=mid;
        mid=(l+r)/2;
    }
    cout<<ans;
}
