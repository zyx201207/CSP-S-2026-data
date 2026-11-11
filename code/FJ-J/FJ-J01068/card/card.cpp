#include<bits/stdc++.h>
using namespace std;
int n,m;
int ans[300005];
int a[500005];
int lastappear[300005];
int cnt[300005];
void count(int i){
	if(i>n)return;
	ans[a[i]]++;
	count(lastappear[a[i]]+1);
}bool checkA(int shu[]){
	for(int i=2;i<=n;i++){
		if(a[i]>a[i-1])return 0;
	}return 1;
} int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	//ÌØ1 
	if(n==m){
		for(int i=1;i<=n;i++){
			ans[a[i]]=i;
		}for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
		return 0;
	}
	//ÌØA
	if(checkA(a)){
		for(int i=1;i<=n;i++){
			ans[a[i]]=i;
		}for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
		cout<<"\n";
		return 0;
	} 
	//±¬Àú 
	for(int i=1;i<=n;i++){
		lastappear[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		count(i);
	}for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
