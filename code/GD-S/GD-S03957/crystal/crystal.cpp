#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll n,m;
ll a[500001];
ll c[500001];
ll q[500001];
ll sum[500001];
ll sm=0;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	//for(int i=1;i<=n;i++)cout<<a[i]<<' ';
	for(ll i=2;i<=n;i++){
		c[i]=a[i]-a[i-1];
		sum[i]=c[i]+sum[i-1];
	}
	
	//cout<<"n,m:"<<n<<m<<'\n';
	//cout<<"c is like:\n";
	
	//for(int i=1;i<=n;i++)cout<<c[i]<<' ';
	//cout<<'\n'; 
	
	ll bg=2;
	ll tmp=0;
	ll mxn=1;
	for(ll ed=2;ed<=n;ed++){
		sm+=(ed-bg)*c[ed];
		sm+=c[ed];
		while(sm>m){
			//cout<<"now bg:"<<bg<<",ed:"<<ed<<",sm="<<sm<<'\n';
			sm-=(q[bg]+(sum[ed]-sum[bg-1]));
			bg++;
		}
		//cout<<"now bg,ed:"<<bg<<' '<<ed<<",mxn="<<mxn<<'\n';
		mxn=max(mxn,ed-bg+2);
	}
	cout<<mxn;
}
