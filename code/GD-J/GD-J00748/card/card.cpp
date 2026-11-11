#include<bits/stdc++.h>
using namespace std;
int a[10000010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int pd=1;
	for(int i=1;i<n;i++){
		if(a[i]!=a[i+1]){
			pd=0;
			break;
		}
	}
	if(pd){
		for(int i=1;i<=m;i++){
			if(i!=a[1]){
				cout<<0<<" ";
			}else{
				cout<<n<<" ";
			}
		}
		return 0;
	}
	int is=1;
	for(int i=1;i<n;i++){
		if(a[i]==a[i+1]){
			is=0;
		}
	}
	if(is){
		int ii=0;
		for(int i=1;i<=m;i++){
			cout<<n-ii<<" ";
			ii++;
		}
		return 0;
	}
	int ii=0;
	for(int i=1;i<=m;i++){
		cout<<n-ii;
		ii++;
	}
	return 0;
}
