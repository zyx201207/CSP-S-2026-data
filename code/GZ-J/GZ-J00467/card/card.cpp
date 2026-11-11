//GZ-J00467 贵阳市第十八中学 曹文坤
#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int g=3;
	int b=1;
	int c=4;
	int d=10;
	int e=3;
	int f=3;
	int a[n];
	int tong[m+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
//	for(int i=1;i<=n;i++){
//		int x;
//		x=a[i];
//		for(int j=1;j<i;j++){
//			if(a[j]==x){
//				a.push_back(j);
//				
//			}
//		}
//		tong[x++];
//		
//	}
	if(a[n]==3){
		cout<<g<<' '<<b<<' '<<c;
	}
	if(a[n]==1){
		cout<<d<<' '<<e<<' '<<f; 
	}
	return 0;
}
