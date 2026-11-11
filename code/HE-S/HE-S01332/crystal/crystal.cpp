#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6+10;
ll n,num,ans,m,a[N];
bool cmp(ll x,ll y){
	return x<y;
}
int main (){
	freopen(" crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	ll mid=0,z=0;
	sort(a+1,a+n+1,cmp); 
	for(int i=1;i<=n;i++){
		z+=a[i];
		mid=z%n;
		//cout<<mid<<endl;
		if(m!=0){
			if(a[i]<mid){
				m--;
				a[i]++;
				cout<<a[i]<<endl;
			}
		}	
		if(a[i]=a[i+1]&&m==0){
			num++;
			if(num%3!=0)ans=(num%3)*3;
			else ans=num;
		}
	}
	printf("%lld",&ans);
	return 0;
}
