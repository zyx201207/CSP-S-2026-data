#include<bits/stdc++.h>
using namespace std;
int a[10005],b[10005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	bool flag=false;
	if(n>m){
		flag=true;
	}
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=1;j<=n;j++){
			if(b[j]==a[i]){
				continue;
			}
		}
		cout<<a[i];
	}
	return 0;
}
