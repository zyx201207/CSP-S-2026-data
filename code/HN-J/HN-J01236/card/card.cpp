#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,m;
int top;
int a[N];
int st[N];
int res[N];
int ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			res[++top]=a[j];
			if(st[a[j]]!=0){
				top=st[a[j]];
			}
			st[a[j]]=top;
		}
		for(int j=1;j<=top;j++){
			ans[res[j]]++;
//			cout<<res[j]<<' ';
		}
//		cout<<'\n';
		for(int j=0;j<=n;j++){
			st[j]=0;
			res[j]=0;
		}
		
		top=0;
//		for(int j=1;j<=n;j++){
//			cout<<ans[j]<<' ';
//		}
//		cout<<'\n';
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
