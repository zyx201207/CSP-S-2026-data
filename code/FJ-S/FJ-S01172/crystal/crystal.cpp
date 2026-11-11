#include<bits/stdc++.h>
using namespace std;
int n;
long long a[500050];
long long m;
long long s,su;
bool vis[110];
int main(){
	freopen("crystal.in ","r",stdin);
	freopen("crystal.out ","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	bool p=1;
	s=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		s=min(a[i],s);
	}
	if(n==1){
		cout<<1;
		return 0;
	}
	if(n==2){
		if(abs(a[2]-a[1])<=m) cout<<2;
		else cout<<1;
		return 0;
	}
	if(n==3){
		sort(a+1,a+n+1);
		if(a[3]-a[1]<=m){
			cout<<3<<endl;
			return 0;
		}
		if(a[3]-a[2]<=m){
			cout<<2<<endl;
			return 0;
		}
		if(a[2]-a[1]<=m){
			cout<<2<<endl;
			return 0;
		}
		cout<<1;
		return 0;
	}
	if(n==4){
		sort(a+1,a+n+1);
		if(a[3]-a[1]+a[4]-a[2]<=m){
			cout<<4<<endl;
			return 0;
		}
		if(a[4]-a[2]<=m){
			cout<<3<<endl;
			return 0;
		}
		if(a[3]-a[1]<=m){
			cout<<3<<endl;
			return 0;
		}
		if(a[4]-a[3]<=m){
			cout<<2<<endl;
			return 0;
		}
		if(a[3]-a[2]<=m){
			cout<<2<<endl;
			return 0;
		}
		if(a[2]-a[1]<=m){
			cout<<2<<endl;
			return 0;
		}
		cout<<1;
		return 0;
	}
	if(n==5){
		sort(a+1,a+n+1);
		if(a[5]-a[1]+a[4]-a[2]<=m){
			cout<<5<<endl;
			return 0;
		}
		if(a[3]-a[1]+a[4]-a[2]<=m){
			cout<<4<<endl;
			return 0;
		}
		if(a[5]-a[3]+a[4]-a[2]<=m){
			cout<<4<<endl;
			return 0;
		}
		if(a[5]-a[3]<=m){
			cout<<3<<endl;
			return 0;
		}
		if(a[4]-a[2]<=m){
			cout<<3<<endl;
			return 0;
		}
		if(a[3]-a[1]<=m){
			cout<<3<<endl;
			return 0;
		}
		if(a[5]-a[4]<=m){
			cout<<2<<endl;
			return 0;
		}
		if(a[4]-a[3]<=m){
			cout<<2<<endl;
			return 0;
		}
		if(a[3]-a[2]<=m){
			cout<<2<<endl;
			return 0;
		}
		if(a[2]-a[1]<=m){
			cout<<2<<endl;
			return 0;
		}
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		su+=(a[i]-s);
		if(a[i]-s<m) p=0;
	}
	if(p){
		cout<<1;
		return 0;
	}
	if(su<=m){
		cout<<n<<endl;
		return 0;
	}
	cout<<n/2-1<<endl;
	return 0;
} 
