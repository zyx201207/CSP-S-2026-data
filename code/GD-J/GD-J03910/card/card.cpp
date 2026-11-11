#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005],t[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int ok1=1,ok2=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]){
			ok1=0;
		}if(a[i]>a[i-1]){
			ok2=0;
		}
	}
	if(ok1 || ok2){
		for(int i=n;i>=1;i--){
			if(t[a[i]]==0){
				ans[a[i]]+=i;
				t[a[i]]=1;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<' ';
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		int k=i;
		for(int j=i;j<=n;j++){
			if(t[a[j]]!=0){
				for(int l=t[a[j]];l<j;l++){
					t[a[l]]=0;
				}
			}
			t[a[j]]=j;
		}
		for(int j=1;j<=m;j++){
			if(t[j])
			ans[j]++;
			t[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
/*
4 3
1 2 1 3
*/
