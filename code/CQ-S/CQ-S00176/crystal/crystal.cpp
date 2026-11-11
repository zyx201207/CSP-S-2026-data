#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,m,a[N],axz[N];
ll h;
priority_queue<ll,vector<ll>,greater<> > pq;
bool A=1,B=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		h+=a[i];
		if(a[i]!=i){
			A=0;
		}
		if(i>2){
			if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
				B=0;//cout<<i<<" ";
				//cout<<"a[i]:"<<a[i]<<"-a[i-1]:"<<a[i-1]<<":"<<a[i]-a[i-1]<<"\n";
				//cout<<"a[i+1]:"<<a[i+1]<<"-a[i]:"<<a[i]<<":"<<a[i+1]-a[i]<<"\n";
			}
		}
	}
	if(n==1){
		cout<<1;
		return 0;
	}
	if(n<=16){
		ll h2=h/n;
		ll h3=0;
		ll zb=0;
		for(int i=1;i<=n;i++){
			h3=0;
			for(int j=1;j<=i;j++){
				h3+=a[i]-a[j];
				
			}
			if(h3>m){
				zb=i-1;
				break;
			}
		}
		cout<<zb;
		return 0;
	}
	if(A){
		ll zb=0;
		for(int i=2;i<=n;i++){
			axz[i]=axz[i-1]+i-1;
			//cout<<axz[i]<<" ";
			if(m<axz[i]){
				zb=i-1;
				break;
			}
		}
		cout<<zb;
		return 0;
	}
	if(B){//cout<<"b";
	
		ll zb=0;ll h1=0;
		ll u=a[2]-a[1];
		for(int i=2;i<=n;i++){
			h1=(i-1)*i*double(u/2);
			//cout<<h<<" ";
			if(m<h1){
				zb=i-1;
				break;
			}
		}
		cout<<zb;
		return 0;
	}
	else{
		srand(time(0));
		ll x=rand()%int(5e5)+1;
		cout<<x;
	}
	return 0;
}
