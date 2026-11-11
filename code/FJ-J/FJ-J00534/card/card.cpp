#include<bits/stdc++.h>
using namespace std;
int n,m,a1,b1,a[5005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=1;i<=n;i++){
		if(a[i]!=a[n]){
			a1++,b1++;
		}if(a[i]==a[n]&&a[i]==1){
			a1++;
		}if(a[i]==a[n]&&a[i]==2){
			b1++;
		}
	}
	cout<<a1<<endl<<b1;
	return 0;
}
