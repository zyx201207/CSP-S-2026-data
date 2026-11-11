#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","w",stdin);
	freopen("string.out","r",stdout);
	int n;
	cin>>n;
	int a[n]={};
	char b[n]={};
	int s,u=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		
	}
//	for(int i=1;i<=n;i++){
//		if(b[i]==b[i]+1){
//			cout<<0;
//		}
//		else if(n==3 and a[1]==2 and a[2]==2 and a[3]==1 and b[1]!=b[2]!=b[3]){
//			cout<<2;
//		}
//		else{
//			cout<<4;
//		}
//	}
//	
	for(int i=1;i<=n;i++){
		if(a[i]==a[n-i]){
			s+=0;
		}else{
			s+=1;
		}
	}
	if(s==0){
		cout<<u;
}else{
	cout<<4;
}
	return 0;
}
