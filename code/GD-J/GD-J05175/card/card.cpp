#include<bits/stdc++.h>
using namespace std;
const int N=500100;
int n,m;
int a[N],ans[N],cnt[N],x[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		x[a[i]]=i;	
	}
	for(int i=n;i>=1;i--){
		cnt[i]=x[a[i]];
		//x[a[i]]=i;
	}
//	for(int i=1;i<=n;i++){
//		cout<<cnt[i]<<" ";
//	}
	//cout<<endl;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;){
			if(j!=cnt[j]){
				j=cnt[j];
			} else {
				ans[a[j]]++;
				j++;
				
			}
		}
		//ans[a[n]]++;
//		for(int i=1;i<=m;i++){
//			cout<<ans[i]<<" ";
//		}
//		cout<<endl;
	}
	for(int i=1;i<m;i++){
		cout<<ans[i]<<" ";
	}
	cout<<ans[m];
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1

*/
/*
4 3
1 2 1 3

*/
