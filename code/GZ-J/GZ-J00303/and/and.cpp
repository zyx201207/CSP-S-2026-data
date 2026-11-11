//GZ-J00303 遵义四中 郑安迪 
#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+5]={};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	if(m==1){
		cout<<a[1];
		return 0;
	}
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
	int sum=a[1];
	for(int i=2;i<=m;i++){
		cout<<a[i]<<endl;
		sum=sum&&a[i];
	}
	cout<<sum; 
	return 0;
}

