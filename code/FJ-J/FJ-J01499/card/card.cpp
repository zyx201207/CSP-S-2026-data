#include <bits/stdc++.h>
using namespace std;
int n,m,a[30005],noww[30005],thro[30005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		noww[i]=a[i];
		if(a[i]==0){
			a[i]++;
			for(int j=1;j<=i;j++){
				noww[i]++;
			}
		}else{
			a[i]=1;
		}
	}
	for(int i=1;i<=n;i++){
		cout<<noww[i];
	}
	return 0;
}
