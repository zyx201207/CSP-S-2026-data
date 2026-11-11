//GZ-J00662 都匀第十中学 郑杰康
#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],maxa=-1;
int dg(int b[200005],int m1,int n1,int ii,int sum){
	if(m1==0){
		maxa=max(maxa,sum);
		return -1;
	}
	for(int i=ii;i<n1;i++){
		if(m1==m){
			dg(b,m1-1,n1,i+1,b[i]);
		}else{
			dg(b,m1-1,n1,i+1,sum&b[i]);
		}	
	}
	return maxa;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==n){
		maxa=a[0];
		for(int i=1;i<n;i++){
			maxa=maxa&a[i];	
		}
		cout<<maxa;
		return 0;
	}
	cout<<dg(a,m,n,0,0);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
