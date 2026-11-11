#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int t=1;
	for(int i=1;i<=n;i++){
		int j=1;
		while(b[j]!=0){
			if(b[j]==a[i]){
				t==j;
			}
		}
		t++;
	}
	for(int i=1;i<=n;i++){
		cout<<b[i]<<endl;
	}
//	4 3
//	1 2 1 3
} 
