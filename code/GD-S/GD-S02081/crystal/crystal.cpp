#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+50; 
const int MAXN=1e12;
const int MAXX=1e5;
int n,m,x;
int a[N]={0},s[N]={0};
int cnt=1,ans=1;
bool A=1,B=1;
void baoli(){
	ans=1;
	sort(a+1,a+n+1); 
	for(int k=1;k<n;k++){
		cnt=1,x=m;
		bool flag=0;
		for(int i=k+1;i<=n;i++){
			if(a[i]==a[i-1]){
				cnt++;continue;
			}if(flag)break;
			x-=(i-k+1)*(a[i]-a[i-1]);
			if(x>=0)cnt++;
			else{
				flag=1;
				continue;
			}
		}ans=max(ans,cnt);
	}cout<<ans+1;
	return ;
}
void find(){
	sort(a+1,a+n+1);
	a[0]=s[0]=0;
	int l=1,r=n;
	for(int i=1;i<=n;i++){
		s[i]=a[i];
		s[i]+=s[i-1];
	}while(l+1<r){
		if(a[l]==a[l+1]){
			++l;continue;
		}if(a[r]==a[r-1]){
			--r;continue;
		}
		if(a[r]*(r-l)-(s[r-1]-s[l-1])<=m)break;
		if(a[l+1]-a[l]>=a[r]-a[r-1])++l;
		else --r;
	}
	for(int i=r+1;i<=n;i++){
		if(a[i]!=a[r])break;
		r++;
	}for(int i=l-1;i>=1;i--){
		if(a[i]!=a[l])break;
		l--;
	}
	cout<<r-l+1;
	return ;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;x=m;
	if(m>=(n-1)*MAXN&&n>5000){
		cout<<n;return 0;
	}if(m>=(n-1)*MAXX&&n<=5000){
		cout<<n;return 0;
	}if(n>5000&&m<=(int)1e8&&m>=(n-1)*100){
		cout<<n;return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)A=0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(i>=3&&(a[i]-a[i-1]!=a[i-1]-a[i-2]))B=0;
	}
	for(int i=2;i<=n;i++){
		if(a[i]==a[i-1]){
			ans++;continue;
		}x-=(i-1)*(a[i]-a[i-1]);
		if(x>=0)ans++;
		else break;
	}
	if(A||B){
		cout<<ans;
		return 0;
	}
	find();
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/
