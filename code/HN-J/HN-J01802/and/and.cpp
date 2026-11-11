#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[200005];
int d(int x,int y){
	int a[9],b[9],c[9],len=8;
	int z=1, ans=0;
	for(int i=0;i<=8;i++)
	{
		a[i]=0;
		b[i]=0;
	}
	while(x>0||y>0){
		a[len]=x%2;
		b[len]=y%2;
		if(a[len]&&b[len])
			c[len]=1;
		else c[len]=0;
		ans+=c[len]*z;
		z*=2;
		x/=2;
		y/=2;
		len--; 
	}
	return ans;
}

int main(){
	//freopen("and.in",r,stdin);
	//freopen("and.out",w,stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];}
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}if(m==n){
		ans=a[1];
		for(int i=1;i<=n;i++){
			ans=d(ans,a[i]);
			cout<<ans;
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++)
			ans=max(ans,d(a[i],a[j]));
	}
	cout<<ans;
	return 0;
} 
