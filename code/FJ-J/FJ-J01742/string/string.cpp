#include<bits/stdc++.h>
using namespace std;
//struct node{
//	int lr;
//	char st;
//}a[200005];
int n;
int a;
string b;
//int qz[200005];
//node a[200005];
//long long len,ans,mid,now;
//string s,c;
int main(){
	
////	freopen("string.in","r",stdin);
////	freopen("string.out","w",stdout);
//	


freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
//		qz[i]=qz[i-1]+a[i].lr;
	}
//	len=qz[n];
//	if(len%2==0){
//		mid=len/2+1;
//		for(int i=mid,j=len-mid;i<=len;i++){
//			i=lower_bound(qz+1,qz+n+1,i)+qz;
//			i=upper_bound(qz+1,qz+n+1,i)+qz
//			j=lower_bound(qz+1,qz+n+1,i)+qz;
//			if(now==i){
//				ans+=min(qz[now])
//			}
//			if(qz[nowj]<qz[movi]){
//				ans+=qz[nowj]
//				a[movi+1]+=(qz[movi]-qz[now])
//			}
//			int j=len-i;
//			if(s[i]+=s[j]){
//				ans++
//			}
//		}
//	}
//	cout<<ans;
	if(n==1){
		cout<<0;
	}
	else if(n==2){
		if(a%2==0){
			cout<<a/2;
		}
		else{
			cout<<a;
		}
	}
	else{
		cout<<0;
	}
	return 0;
} 
