#include<bits/stdc++.h>
using namespace std;
int a[500009],b[300009];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int t=i;
		for(int j=i;j<=n;j++){
			for(int o=t;o<j;o++){
				if(a[o]==a[j]){
					t=j;
				}
			}
		}
		for(int o=t;o<=n;o++){
			b[a[o]]++;
			cout<<b[a[o]]<<" ";
		}
		cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	cout<<'\n';
	return 0;
}
