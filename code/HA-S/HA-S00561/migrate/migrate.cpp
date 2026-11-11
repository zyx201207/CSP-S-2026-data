#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int n,m,cnt=0;
	cin>>n>>m;
	for(int i=0;i<=n;i++){
		cin>>a[i];
		if(a[i]=a[i+1]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
