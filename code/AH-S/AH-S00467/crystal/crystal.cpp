#include<bits/stdc++.h>
#define int long long
using namespace std;
int A[500005];
__int128 a[500005],b[500005],m;
int cnt,ans,n,M;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>M;
	m=M;
	for(int i=1;i<=n;i++){
		cin>>A[i];
		a[i]=A[i];
	}
	sort(a+1,a+n+1);
	int l=1,ans=1;
	__int128 s=0;
	b[1]=a[1];
	for(int i=2;i<=n;i++){
		b[i]=a[i];
		a[i]=b[i]-b[i-1];
	}
	a[1]=0;
	for(int r=1;r<=n;r++){
		if(r==1){
			s=a[1];
			ans=max(ans,r-l+1);
		}else{
			s+=a[r]*(r-l);
			if(s>m){
				while(s>m){
					s-=(b[r]-b[l-1]);
					l++;
				}
			}
			ans=max(ans,r-l+1);
			//cout<<r<<" "<<l<<" "<<sum<<"\n";
		}
	}
	cout<<ans;
}
