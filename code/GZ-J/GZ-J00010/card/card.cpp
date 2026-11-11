//GZ-J100010 六盘水市第四实验中学 彭荣锦
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[600000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cout<<m-i+1<<" ";
	}
	return 0;
} 
