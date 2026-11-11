#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
int a[N],b[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >>n>>m;
	for(int i=1;i<=n;i++){
		cin >>a[i];
	}
	for(int i=1;i<=m;i++){
		for(int s=i;s<=n;s++){
			b[s]=a[s];
		}
		for(int j=i;j<=n;j++){
			
		}
	}
	return 0;
}
