#include<bits/stdc++.h>
using namespace std;
long long n,m;
int a[500005];
int ans[300005];
int b[500005];
void find(int p,int idx){
	for(int i=1;i<idx;i++){
		if(a[i]==p){
			for(int j=i;j<=n;j++){
				b[j]=0;
			}
			b[i]=p;
		}
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			b[j]=a[i];
			find(b[j],j);
		}
		for(int j=1;j<=n;j++){
			if(b[j]!=0){
				ans[b[j]]++;
			}
		}
		for(int j=1;j<=n;j++){
			b[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
