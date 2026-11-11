#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	int n,m;
	cin>>n>>m;
	int c[m+1]={0},a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int b[m+1]={0};
		for(int j=i;j<=n;j++){
			c[a[j]]++;
			if(b[a[j]]==0){
				b[a[j]]=1;
			}else{
				c[a[j]]--;
				b[a[j]]=0;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
} 
