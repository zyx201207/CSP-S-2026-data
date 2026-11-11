#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5+10;
ll a[N];
ll s[N];
ll c[N]; 
ll sum = 1e18;
ll n,m;
ll ans = 0;
bool cmp(ll a,ll b){
	return a<b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	for(ll i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(ll i = 1;i<=n;i++){
		if(i==n){
			s[i] = 0;
			c[i] = c[i-1];
			continue;
		}
		s[i] = a[i+1]-a[i];
		c[i] = c[i-1]+s[i];
	}
	ll flag = 1;
	for(ll i = 1;i<n-1;i++){
		
		if(s[i]!=s[i+1]){
			flag = 0;
		}
	}
	if(flag){
		cout<<m/s[1];
		return 0;
	}
	for(ll i = 1;i<=n;i++){
		for(ll j = n;j>i;j--){
			if(c[j]-c[i]<=m){
				//cout<<"找到合法i:"<<i<<" j:"<<j<<endl; 
				ll p = abs((c[j]-c[i-1])-m);
				if(sum>p){
					//cout<<"更新答案，答案累计:"<<p<<" 答案:"<<(j-i)+1<<endl;
					sum = p;
					ans = (j-i)+1;
				}else{
					continue;
				}
			}else{
				continue;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
