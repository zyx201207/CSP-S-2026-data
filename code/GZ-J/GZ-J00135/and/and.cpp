//GZ-J00135 观山湖区外国语实验中学（南校区） 安辉煌
#include <bits/stdc++.h>
using namespace std;
long long n,m,a[20005],maxn;
long long yu(long long m){
	for(int i=1;i<=m;i++){
		int z[100000]={};
		for(int j=1;j<=a[i].size;j++){
			z[j]=a[i]%2;
			a[i]/=2;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	return 0;
} 

