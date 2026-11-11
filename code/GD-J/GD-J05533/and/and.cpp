#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000010],f[100010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=m;j>=1;j--){
			if(j>1){
				f[j]=max(f[j-1]&a[i],f[j]);
			}
			else{
				f[j]=max(a[i],f[j]);
			}
		}
	}
	cout<<f[m];
	return 0;
}
//4 2
//3 15 12 12
