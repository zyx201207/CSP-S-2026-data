#include<bits/stdc++.h>
using namespace std;
int a[505],n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=1;j<=i;j++){
			if(a[j]==x){
				for(int z=j;z<=i;z++)a[z]=0;
			}
		}
		a[i]=x;
	}
	for(int i=1;i<=m;i++){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(a[j]==i){
				cnt++;
				break;
			}
		}
		cout<<cnt<<' ';
	}
	
	return 0;
}
