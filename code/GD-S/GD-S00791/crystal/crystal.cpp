#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll=long long;
typedef pair<int,int> pii;
const int N=5e5+50;
int n,ans=1;
ll m,a[N],s[N];
bool valid(int i,int j){
	return j<=i-ans&&a[i]*(i-j+1)-(s[i]-s[j-1])>m;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		s[i]=s[i-1]+a[i];
		int p=1,j=1;
		while(valid(i,j)&&p){
			if(valid(i,j+p))j+=p,p*=2;
			else p/=2;
		}
		if(j<=i-ans&&!valid(i,j))ans=max(ans,i-j+1);
		else if(j<i-ans&&!valid(i,j+1))ans=max(ans,i-j);
//		for(int j=1;j<=i-ans;++j){
//			if(a[i]*(i-j+1)-(s[i]-s[j-1])<=m){
//				ans=max(ans,i-j+1);break;
//			}
//		}
	}
	cout<<ans;
	return 0;
} 
