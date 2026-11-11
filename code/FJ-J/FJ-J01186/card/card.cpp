#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005]={0},c[500005],d[500005];
int main(){
	freopen("card","r",stdin);
	freopen("card","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		for(int i=1;i<=n+1-i;i++){
			if(c[a[i]]>=2){
				b[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i];
	}
	return 0;
}
