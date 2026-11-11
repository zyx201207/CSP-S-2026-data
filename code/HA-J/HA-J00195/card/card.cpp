#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m;
int a[N];
int ans[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==2){
		if(a[1]==a[2]){
			ans[a[1]]=2;
		}else{
			ans[a[1]]=1;
			ans[a[2]]=2;
		}
	}else if(n==3){
		if(a[1]==a[2]&&a[1]==a[3]){
			ans[a[1]]=3;
		}else if(a[1]==a[2]){
			ans[a[1]]+=2;
			ans[a[3]]=3;
		}else if(a[1]==a[3]){
			ans[a[3]]=3;
			ans[a[2]]=2;
		}else if(a[2]==a[3]){
			ans[a[2]]=3;
			ans[a[1]]=1;
		}else{
			ans[a[1]]=1;
			ans[a[2]]=2;
			ans[a[3]]=3;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

