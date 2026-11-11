#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+5];
	int b[m+5];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]==0;
	}
	int c[m+5][4];
	b[2]=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			b[a[j]]++;
		}
	}//统计总数 
	
	//for(int i=1;i<=n;i++){
	//	for(int j=i+1;j<=n;j++){
	//		if(c[a[j]][0]>1){
	//			
	//		}
	//		c[a[j]][0]++;
	//		c[a[j]][1]=j;
	//	}
	//}//标记有重 
	
	//for(int i=1;i<=n;i++){
	//	if(c[i]==1){
	//		for(int i=1;i<=n;)
	//	}
	//}//减数 
	
	for(int i=1;i<=m;i++){
		cout<<b[i]<<' ';
	}
	return 0;
}
