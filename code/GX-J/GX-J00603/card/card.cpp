#include<bits/stdc++.h>
using namespace std;
long long int n,m,a[1000000],c[1000000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int w=1;w<=n;w++){
		for(int i=w;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]==a[j]){
				i=j;
				break;
			}
		}
		c[a[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
	cout<<c[i]<<" ";
	}
	
	return 0;
}
