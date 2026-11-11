#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005];
int desk[500005];
int yu[500005];
int ans[500005];
int find(int num,int ptr){
	for(int i=1;i<=n;i++){
		if(desk[i]==num&&i!=ptr){
			return i;
		}
	}
	return -1;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int cnt=1;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			desk[j]=a[j];
			int k=find(desk[j],j);
			if(k!=-1){
				for(int x=k;x<j;x++){
					yu[cnt]=desk[x];
					cnt++;
					desk[x]=0;
				}
			}
		}
		for(int j=1;j<=n;j++){
			if(desk[j]!=0) ans[desk[j]]++;
			desk[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
