#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int b[300005];
int nxt[500005];
int lst[300005];
int ans[300005];
bool flagA=1;
void solveA(){
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
}
void solve(){
	for(int i=n;i>=1;i--){
		if(lst[a[i]]==0) lst[a[i]]=i;
		nxt[i]=lst[a[i]];
		lst[a[i]]=i;
	}
	for(int i=n,j=n;i>=1;i--){
		if(a[i]==a[j]){
			nxt[i]=j;
		}
		else{
			j=i;
		}
	}
//	for(int i=1;i<=n;i++) cout<<nxt[i]<<" ";
	for(int k=1;k<=n;k++){
	//	cout<<k<<"\n";
		for(int j=k;j<=n;j++){
			while(nxt[j]!=j) j=nxt[j];
			ans[a[j]]++;
//			cout<<j<<"\n";
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
}
int main(){ 
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]=i;
		if(a[i]<a[i-1]) flagA=0;
	}
	if(flagA){
		solveA();
	}
	else{
		solve();
	}
	return 0;
}
