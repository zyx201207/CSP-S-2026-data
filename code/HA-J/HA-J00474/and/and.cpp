#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m,a,s=0,j=1;
	cin>>n>>m;
	vector<ll>ve(n);
	for(int i=0;i<n;i++){
		s=0;j=1;
		cin>>a;
		while(a){
			s+=a%2*j;
			a/=2;
			j*=10;
		}
		//cout<<s<<" ";
		ve[i]=s;
	}
	ll l=2,sum_=0,max_=LLONG_MIN,u,d;
	for(int i=0;i<n;i++){
		//cout<<ve[i]<<" ";
		for(int j=i+1;j<n;j++){
			sum_=0;
			while(ve[i]){
				u=ve[i]%10;
				d=ve[j]%10;
				if(u%10==1&&d%10==1){
					sum_+=u%10*l;
				}
				ve[i]/=10;
				ve[j]/=10;
				l*=2;
			}
			//cout<<sum_<<" ";
			max_=max(max_,sum_);
		}
	}
	cout<<max_;
	return 0;
}
