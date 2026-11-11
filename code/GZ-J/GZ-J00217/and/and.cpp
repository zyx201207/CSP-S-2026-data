//GZ-J00217,金沙第一中学，姓名：王俊泽 
#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int a[maxn];
int n,m,sum=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			sum=max(sum,i^j);
		}
	}
	return 0;
}
