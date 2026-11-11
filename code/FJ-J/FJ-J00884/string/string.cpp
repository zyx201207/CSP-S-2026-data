#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
struct node{
	ll ant;
	char u;
};
ll n;
node a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n;
	ll sum=0;
	
	int k=0;
	for(int i=1;i<=n;i++){
		
		long long cu;
		char ut;
		cin>>cu;
		cin>>ut;
		if(i==1){
			++k;
			a[k].ant=cu;
			a[k].u=ut;
		}
		else if(ut!=a[k].u){
			k++;
			a[k].ant=cu;
			a[k].u=ut;
		}else a[k].ant+=cu;
		sum+=cu;
	}
	
	
	sum/=2;
	int l=1,r=k;
	ll ans=0;
	while(true){
		ll mi=min(a[l].ant,a[r].ant);
		if(a[l].u==a[r].u){
			sum-=mi;
			a[l].ant-=mi;
			a[r].ant-=mi;
		}else {
			ans+=mi;
			sum-=mi;
			a[l].ant-=mi;
			a[r].ant-=mi;
		}
		if(a[r].ant<=0) r--;
		if(a[l].ant<=0) l++;
		if(sum<=0) break;
	}
	cout<<ans;
	return 0;
}
