#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N],f[N],num[50];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	num[0]=1;
	for(int i=1;i<=40;i++){
		num[i]=num[i-1]*2;
	}
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		bool t=0;
		for(int j=1;j<=40;j++){
			if(num[j]==a[i])t=1;
		}
		if(t==0)flag=0;
	}
	if(flag){//a[i]¾ùÎª2^ki-1 
		sort(a+1,a+n+1);
		cout<<a[n-m+1]<<endl;
		return 0;
	}
	f[0]=1;
	for(int i=1;i<=32;i++){
		f[0]*=2;
	}
	f[0]-=1;
	for(int i=1;i<=n;i++){
		for(int j=m;j>=1;j--){
			if(j>i)continue;
			f[j]=max(f[j],f[j-1]&a[i]);
		}
	} 
	cout<<f[m]<<endl;
	return 0;
}
