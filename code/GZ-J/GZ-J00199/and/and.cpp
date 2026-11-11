//GZ-J00199 遵义市第一初级中学 刘致江 
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N],dp=0;
int yu(int j,int m){
	int count=0;
	if(m!=2){
		return yu(j-1,m-1)&a[j];
	}
	if(j==m){
		count=a[1]&a[2];
		return count;
	}else{
		for(int i=1;i<=j-m+1;i++){
			for(int k=i+1;k<=j;k++){
				count=a[i]&a[k];
				dp=max(dp,count);	
			}
		}
	}
	return dp;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n;	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<yu(n,m);
	return 0;
}
