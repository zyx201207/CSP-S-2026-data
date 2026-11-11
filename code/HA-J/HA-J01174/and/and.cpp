#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","w",stdin);
	freopen("and.out","r",stdout);
	int n[10001],m,a;
	cin >>a>>m;
	for(int i=1;i<=a;i++){
		cin >>n[i];
	}
	int max=-1000001;
	for(int i=1;i<=a-m;i++){
		int u=n[i];
		for(int j=1;j<=m;j++){
			u=u&n[i+j];
		}
		if(max<u){
			max=u;
		}
	}
	cout <<max;
	return 0;
}