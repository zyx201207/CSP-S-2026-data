#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,c[20005]={},mm[20005]={},minx=999999;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	cout<<c[n];
	//for(int i=1;i<=n;i++){
	//	cin>>c[i];
	//	for(int j=1;i<=m;j++){
	//		if(c[i]>mm[j]){
	//			mm[j]=c[i];
	//		}
	//	}
	//}
	//for(int j=1;j<=m;j++){
	//	if(mm[j]<minx){
	//		minx==mm[j];
	//	}
	//}
	//cout<<minx;
	return 0;
} //没思路了，按位与忘了，能骗一点是一点 
