#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,ans,maxx;
int a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[j]!=a[j+1]){
				cnt=j;
				break;
			}
		}
		a[cnt]++;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i]==a[j]) ans++;
		}
		maxx=max(maxx,ans);
		ans=0;
	}
	cout<<maxx;
	return 0;
} 
//5 10
//1 3 5 7 9
