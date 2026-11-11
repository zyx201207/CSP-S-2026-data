#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=5e5+5;

int n;
ll a[N]={},m;
ll cha[N]={};//cha[i]为a[i+1]-a[i] 

void solven2(){
	int ans=-1;
	for(int i=1;i<n;++i){//以i为端点 
		ll sum=0;
		for(int j=i;j<n;++j){
			ll add=1LL*cha[j]*j;
			if(sum+add>m){
				break;
			}
			ans=max(ans,j-i+2);
			sum+=add;
		}
	}
	cout<<ans<<"\n";
}

void solvea(){
	cout<<n<<"\n";
}

void solveb(){
	ll d=cha[1];//公差
	m*=2;
	bool f=1;
	for(int i=1;i<=n;++i){
		ll sum=d*i*(i-1);
		if(sum>m){
			cout<<i-1<<"\n";
			f=0;
			break;
		}
	}
	if(f)cout<<n<<"\n";
}

void solve(){
	
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	bool A=1,B=1;
	cin>>n>>m;
	cin>>a[1];
	for(int i=2;i<=n;++i){
		cin>>a[i];
		if(a[i]!=a[i-1])A=false;
	}
	sort(a+1,a+n+1);
	cha[1]=a[2]-a[1];
	for(int i=2;i<n;++i){
		cha[i]=a[i+1]-a[i];
		if(cha[i]!=cha[i-1])B=false;
	}
	if(n<=5000){
		solven2();
	}
	else if(A){
		solvea();
	}
	if(B){
		solveb();
	}
	else{
		solve();
	}
	return 0;
}
