#include<bits/stdc++.h>
using namespace std;
long long n,xb=1,zz;
char a[20000010];
int main(){
	//大数据不过 
	//记得删测试文件 
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		long long x;
		char zf;
		cin>>x>>zf;
		for(int i=0;i<x;i++){
			a[xb++]=zf;
		}
	}
	xb--;
	for(int i=1;i<=xb/2;i++){
		if(a[i]!=a[xb-i+1]){
			zz++;
		}
		if(i+1==xb-i+1&&i==xb-i+1){
			break;
		}
	}
	cout<<zz;
	return 0;
}
