#include <bits/stdc++.h>
using namespace std;
bool in(long long a){
	while(a%2 == 0 && a != 1){
		a /= 2;
		if(a == 1)return 1;
		if(a%2 != 0) return 0;
	}
	return 0;
}
bool cmp(long long a,long long b){
	if(!in(a) && !in(b)){
		return a > b;
	}else{
		if(in(a)){
			if(a > b*2){
				return a > b;
			}else{
				return a < b;
			}
		}else{
			if(b > a*2){
				return a > b;
			}else{
				return a < b;
			}
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,ans=pow(2,30)-1,l[200005];
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>l[i];
	sort(l+1,l+n+1,cmp);
	for(int i=1;i<=m;i++){
		ans = ans && l[i];
	}
	cout<<ans;
	return 0;
}
