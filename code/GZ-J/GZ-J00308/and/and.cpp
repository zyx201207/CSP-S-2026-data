//GZ-J00308  ฐื๐ุบþะกังฮโณฟุ๊ 
#include <bits/stdc++.h>
using namespace std;
bool cmp(int x, int y){
	return x > y;
}
int a[100000005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i = 1;i<=n;i++){
		if(i==m){
			cout<<a[i];
			break;
		}
	}
    return 0;
}
