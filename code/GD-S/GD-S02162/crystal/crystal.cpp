#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,maxn;
int a[N];
bool f=1,ff=1;
void solve1(){
	for(int i=1;i<=n;i++){
		int s=0,cnt=1;
		for(int j=i-1;j>=1;j--){
			s+=abs(a[i]-a[j]);
			if(s>m) break;
			cnt++;
		}
		maxn=max(maxn,cnt);
	}
	cout<<maxn;
}
void solveA(){
	for(int i=1;i<=n;i++){
		int k=(i-1)*i/2;
		if(k>m){
			cout<<i-1;
			return ;
		}
	}
	cout<<n;
}
void solveB(){
	int st=a[2]-a[1];
	for(int i=1;i<=n;i++){
		int k=(i-1)*(st+st*(i-1))/2;
		if(k>m){
			cout<<i-1;
			return ;
		}
	}
	cout<<n;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(a[i]!=i) f=0;
		if(i>2&&(a[i]-a[i-1])!=(a[i-1]-a[i-2])){
			ff=0;	
		}
	}
	if(n<3) ff=0;
	if(f){
		solveA();
		return 0;
	}
	if(ff){
		solveB();
		return 0;
	}
	solve1();
	return 0;
}
