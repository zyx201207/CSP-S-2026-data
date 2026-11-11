#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],mx=-1,sum,ans=-1,ma=-1;
vector<long long>v;
void dfs(long long inx,long long last){
	if(inx==m){
		long long num=v[0];
		for(int i=1;i<v.size();i++){
			num&=v[i];
		}
		ma=max(ma,num);
		return;
	}
	for(int i=last+1;i<=n-(m-inx)+1;i++){
		v.push_back(a[i]);
		dfs(inx+1,i);
		v.pop_back();
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(m==1){
		cout<<mx;
		return 0;
	}
	if(m==n){
		sum=a[1];
		for(int i=2;i<=n;i++){
			sum=a[i]&sum;
		}
		cout<<sum;
		return 0;
	}
	if(m==2&&n<=2000){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	dfs(0,0);
	cout<<ma;
	return 0;
}
