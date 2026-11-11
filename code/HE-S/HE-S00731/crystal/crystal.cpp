#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,c;//n:水晶的数量 m:最多可以进行的操作次数
	int sum=0;
	cin>>n>>m;
	//输入 a[i]
	int a[n+1],b[n+1];
	for(int i=1;i<=n;i++) {//输入 ai 
			cin>>a[i];
			b[i]=a[i];
		}
	for(int j=1;j<=m;j++){
		b[1]+=1;
		for(int i=1;i<=n-1;i++) {//排序（从小到大） 
			//cin>>a[i];
			if(b[i+1]<b[i]){
				c=b[i+1];
				b[i]=b[i+1];
				b[i+1]=c;
			} 
		}	
	}
	return 0;
} 

