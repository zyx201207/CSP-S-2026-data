#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;int sum=0;
int vis[100];
int num=0;int flag=0;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n<=1){
		cout<<0<<endl;
		return 0;
	}
	for(int i=0;i<n;i++){
		 int ai,ci;
		 cin>>ai>>ci;
		 if(i==0){
		 	num=ci;
		 }else if(num==ci&&flag==0){
		 	flag=0;
		 }else{
		 	flag++;
		 	num=0;
		 }
	}
	if(flag==0){
		cout<<0<<endl;
		return 0;
	}
	cout<<flag<<endl;
	return 0;
}
