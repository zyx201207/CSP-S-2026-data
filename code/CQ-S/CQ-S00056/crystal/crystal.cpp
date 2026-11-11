#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n,m,m1;
int sum;
ll a[500005],f[500005];

void dfs(int x,int g){
	for(int i=x;i>=1;i--){
		if(g-a[i]<=m1){
			m1=m1-g+a[i];
			sum++;
			//cout<<x<<" "<<m1<<endl;
		}else return;
	}
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	m1=m;
	ll cha;
	bool l=1,l1=1;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]!=i)l=0;
		if(i==2){
			cha=a[2]-a[1];
		}else if(i>2){
			if(a[i]-a[i-1]!=cha)l1=0;
		}
	}
	if(l){
		for(ll i=sqrt(m)+1;;i--){
			if(i*(i+1)/2<=m){
				cout<<min(n,i+1);
				return 0;
			}
		}
	}
	if(l1){
		for(ll i=sqrt(m/cha)+1;;i--){
			if(i*(i+1)/2<=m/cha){
				cout<<min(n,i+1);
				return 0;
			}
		}
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)f[i]=f[i-1]+a[i];
	int maxx=1;
	for(int i=2;i<=n;i++){
		m1=m;
		sum=0;
		ll u=f[i]-f[i-maxx];
		if(a[i]*maxx-u>m)continue;
		m1-=(a[i]*maxx-u);
		//cout<<"goal:"<<a[i]<<" start:"<<i<<"\n";
		dfs(i-maxx,a[i]);
		//cout<<"sum:"<<sum<<"\n";
		maxx+=sum;
	}
	cout<<maxx;
	return 0;
} 
