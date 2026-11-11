#include <bits/stdc++.h>
using namespace std;

long long m,n;  //m:操作次数  n:水晶数量
long long a[500001]={};  //水晶能量值 

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	vector <long long> fn(m*2,0);  //动态表
	for (int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	for (int i=1;i<=n;i++){
		for (long long j=m;j>=1;j--){
			fn[j]=max(fn[a[i]]+1,fn[j]);
		}
	}
	cout<<fn[m];
	return 0;
}
