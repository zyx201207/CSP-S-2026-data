#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,c[1005]={0},t=0,a[300005]; 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
			cin>>a[i];
	}
	while(n!=0){
		t++;
		for(int i=t;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(a[i]==j)c[i]=n;
			}
		}
		n--;
	}
	cout<<c[1];
	if(n%2==0){
		for(int i=2;i<=m;i++){
			cout<<" "<<m;
		}
	}
	else{
		cout<<" "<<"1";
		for(int i=3;i<=m;i++){
			cout<<" "<<n;
		}
	}
	return 0;
}
