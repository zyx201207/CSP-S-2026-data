#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000005];
int i2[7]={1,2,4,8,16,32,64};
int cmp(int x,int y){
	return x>y;
}
int and_(int x,int y){
	string x1,y1;
	while(x!=0){
		char a=x%2+'0';
		x1+=a;
		x/=2;
	}
	while(y!=0){
		char a=y%2+'0';
		y1+=a;
		y/=2;
	}
	long long ans=0;
	for(int i=max(x1.size(),y1.size())-1;i>=0;i--){
		if(x1[i]=='1' and y1[i]=='1'){
			ans+=i2[i];
		}
	}
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	long long k=a[1];
	for(int i=2;i<=m;i++){
		k=and_(a[i],k);
	}
	cout<<k;
	return 0;
}
