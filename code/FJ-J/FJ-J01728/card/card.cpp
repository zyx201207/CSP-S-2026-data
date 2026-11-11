#include<bits/stdc++.h>
using namespace std;
int n,m,x,a[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x;
		a[x]++;
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=0){
			cout<<a[i]<<" ";
		}
	}
	return 0;
}
