#include<bits/stdc++.h>
using namespace std;
const int N=1e7;
int n,m,a[N];
bool cmp(int a,int b){
	return a>b;
}
int IF_M(int x){
	int sum=0;
	int ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]<=a[x]&&sum+(a[x]-a[i])<=m){
			sum+=a[x]-a[i];
			a[i]=a[x];
		}else if(sum+(a[x]-a[i])>m) break;
	}
	for(int i=1;i<=n;i++){
		if(a[i]==a[x]) ans++;
	}
	return ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	int maxx=0;
	for(int i=1;i<=n;i++){
		maxx=max(maxx,IF_M(i));
	}
	cout<<maxx;
	return 0;
}
