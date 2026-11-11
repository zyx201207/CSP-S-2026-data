#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=5e5+9;
int n,maxx;
ll a[N],qz[N],m;
int main(){
	ios::sync_with_stdio();
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];

	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) qz[i]=qz[i-1]+a[i];

	for(int i=1;i<=n;i++){
        int l=1,r=i,mid;
        while(l<r){
            mid=(l+r)/2;
            ll now=qz[i]-qz[mid-1];
            ll tot=a[i]*(i-mid+1);
            if(tot-now<=m) r=mid;
            else l=mid+1;
        }
        maxx=max(maxx,i-l+1);
	}
	cout<<maxx;
	return 0;
}
