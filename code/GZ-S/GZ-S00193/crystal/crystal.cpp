//GZ-S00193 »ÆÈË÷ë 
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,diff[N],m,a[N],ave;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],ave+=a[i];
	ave/=n;
	int x,y;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(ave<=a[i]){
			x=a[i],y=a[i+1];
			break;
		}
	}
	cout<<ave<<"¡¡"<<x<<"\n";
	for(int i=1;i<=n;i++) diff[i]=abs(a[i]-x);
	sort(diff+1,diff+n+1);
	int cnt=0;
	for(int i=1;i<=n;i++){
		cnt+=diff[i];
		if(cnt>m) return cout<<i-1,0;
		if(cnt==m) return cout<<i,0;	
//		cout<<cnt<<" ";
	}
	cout<<n;
	return 0;
}

