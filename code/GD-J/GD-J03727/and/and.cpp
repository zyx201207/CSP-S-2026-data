#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],f[200010];//选j个的按位与最大值 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	f[0]=(long long)(pow(2,31)-1);
	for(int i=1;i<=n;i++){
		for(int j=m;j>=1;j--){
			
			f[j]=max(f[j],(f[j-1]&a[i]));
		}
	}
	cout<<f[m];
	return 0;
}
