#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500010],ans;
int f(int id){
	int i=id,cost=0,cnt=0;
	while(i>=1){
		if(cost+(a[id]-a[i])>m) break;
		++cnt;
		cost+=a[id]-a[i];
		--i;
	}
	return cnt;
}
bool tst13to15(){
	for(int i=1;i<=n;i++){
		if(a[i]!=i) return false;
	}
	return true;
}
bool tst16to18(){
	if(n<=2) return true;
	int d=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=d) return false;
	}
	return true;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	if(tst13to15()){
		int i=1,sum=0;
		for(;i<=n;i++){
			if(sum+i>m) break;
			sum+=i;
		}
		cout<<i;
	}else if(tst16to18()&&n>5e3){
		int i=1,sum=0;
		for(;i<=n;i++){
			int x=i*(a[2]-a[1]);
			if(sum+x>m) break;
			sum+=x;
		}
		cout<<i;
	}else{
		for(int i=1;i<=n;i++){
			ans=max(ans,f(i));
		}cout<<ans;		
	}
	
	return 0;
}
