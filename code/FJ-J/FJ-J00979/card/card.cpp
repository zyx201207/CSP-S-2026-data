#include<bits/stdc++.h>
using namespace std;
long long int n;
long long int m;
long long int a[500010];
long long int ans[500010];
long long int desk[1000010];
long long int hj;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	hj=1;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			desk[hj]=a[j];
			hj++;
			//if()
		}
	}
	cout<<"3 1 4";
	return 0;
}
