#include<iostream>
using namespace std;
#define ll long long

ll a[2000010];
int f[2000010],d[2000010];

void solve1(){
	int n;
	ll D;
	cin>>n>>D;
	for(int i=0;i<n;i++)cin>>a[i];
	ll ans=0;
	for(int i=0;i<n;i++){
		int l=i,r=i;
		f[i]=1,d[i]=0;
		for(int j=i+1;j<n;j++){
			if(a[j]-a[j-1]>D)break;
			while(a[l]+D<a[j])l++;
			d[j]=d[l]+1;
			if(l>r)r=j-1;
			if(r-l+1==1)f[j]=f[l];
			else if(r-l+1==2)f[j]=min(f[l]+f[r],3);
			else f[j]=3;
//			cout<<i<<" "<<j<<" "<<f[j]<<"\n";
			if(f[j]==2)ans++;
		}
	}
	cout<<ans<<"\n";
}

void solve2(){
	int n;
	ll D;
	cin>>n>>D;
	for(int i=0;i<n;i++)cin>>a[i];
	if(n<=3){
		cout<<"0\n";return ;
	}
	ll x=a[1]-a[0];
	if(D/x<=1)cout<<"0\n";
	else cout<<max(n-(2*(D/x)-1),0ll)<<"\n";
}

void solve3(){
	int n;
	ll D;
	cin>>n>>D;
	for(int i=0;i<n;i++)cin>>a[i];
	if(n<=3){
		cout<<"0\n";return ;
	}
	int r=0,p=0;
	ll ans=0;
	for(int i=0;i<n;i++){
		while(r<n&&a[i]+D>=a[r])r++;
		if(r<2)continue;
		while(p<n&&r>=3&&a[r-3]+D<=a[p])p++;
		ans+=n-max(p,r);
	}
	cout<<ans<<"\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		if(1<=c&&c<=10)solve1();
		else if(c==11||c==12)solve2();
		else if(c==13||c==14)solve3();
		else solve1();
	}
}
