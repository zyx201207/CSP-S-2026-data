#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[200005];
bool cmp(ll a,ll b){
	return a>b;
}
bool check(){
	for(int i=1;i<=m;i++){
		if(a[i]==0){
			return 0;
		}
	}return 1;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	if(m==1){
		cout<<a[1];
		return 0;
	}
	ll q=0;
	ll maxx=0;
	for(int j=1;j<=n-m+1;j++){
	ll sum=0;
	while(check()){
		bool p=1;
		for(int i=j+1;i<=j-1+m;i++){
			if(a[i]%2==0){
				p=0;
			}
			a[i]/=2;
		}
		if(p==1){
			sum+=pow(2,q);
		}
		q++;
	}
		maxx=max(sum,maxx);
	}
	cout<<maxx;
	return 0;
} 
