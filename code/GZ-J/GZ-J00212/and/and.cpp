//GZ-J00212 遵义市第一初级中学 杨铠溢 
#include <bits/stdc++.h>
using namespace std;
long long a[2000005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ma=0;
	for(int i=1;i<=m;i++){
		for(int j=2;j<=n;j++){
			ma=max(a[j]&a[j-1],ma); 
		}
	} 
	cout<<ma; 
	return 0;
} 
