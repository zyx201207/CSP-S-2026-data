#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
typedef long long ll;
int n,m;
ll a[N],ans=INT_MAX;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans&=a[i];
	}
//	for(int i=1;i<=n;i++)printf("%lld ",a[i]);
	if(m==1){
		printf("%lld",a[1]);
		return 0;
	}
	if(m==n){
		printf("%lld",ans);
		return 0;
	}
	if(m==2){
		ans=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		printf("%lld",ans);
		return 0;
	}
	else{
		ans=0;
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=1001 and i+m-1<=n;i++){
			ll t=a[i];
			for(int j=i+1;j<m+i;j++){
				t&=a[j];
			}
			ans=max(ans,t);
		}
		printf("%lld",ans);		
	}
	fclose(stdin);
	fclose(stdout);
}
/*
5 3
31 3 1 15 7
*/
