//GZ-J00587 六盘水市第二十四中学 许浩然 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,c=0,f=0;
	int cut=0;
	cin>>n;
	char a[n*2+100];
	for(int i=1;i<=n;i++){
		int x;
		char y;
		cin>>x>>y;
		c+=x;
		for(int j=0;j<x;j++){
			a[++f]=y;
		}
	}
	for(int i=1,j=c;i<=c/2;i++,j--){
		if(a[i]!=a[j]){
			cut++;
		}
	}
	cout<<cut;
	return 0;
}
