#include <bits/stdc++.h>
using namespace std;
int n,m;
const int N=5e5+5;
int a[N];
int cnt;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}

	for(int i=1;i<=m;i++){
		cnt=0;
		for(int j=1;j<=n;j++){
			for(int z=j;z<=n-(n-j);z++){
				if(a[z]==i){
					cnt++;
				}
			}
			
		}
		cout<<cnt<<" ";
	}
	return 0;
}
