#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
int n;
ll m,a[N],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll i=1;
	while(m>0){
		a[i]++;
		m--;
		if(a[i+1]>=a[i])i++;
		else{
			ans=max(ans,i);
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i+1])ans=i-1;
	}
	cout<<ans;
	return 0;
}
//:(
