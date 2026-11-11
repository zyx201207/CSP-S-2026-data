#include<bits/stdc++.h>
using namespace std;
int n,m,c,s[33],z,zs,ans,asd[200004][2003];
struct node{
	int id;
	long long su;
}a[200004];
bool cmn(node x,node y){
	return x.id>y.id||(x.id==y.id&&x.su>y.su);
}
void wl(int x,int y){
	c=0;
	while(x!=0||y!=0){
		c++;
		s[c]=(y%2)&(x%2);
		x/=2;
		y/=2;
	}
	zs=0;
	for(int i=0;i<=c-1;i++){
		zs=zs+s[i+1]*pow(2,i);
	}
}
void sus(int t,int m,int sum){
	if(m==0){
		ans=max(ans,sum);
		return;
	}
	if(t+m>n){
		return;
	}
	if(asd[t][m]>=sum&&asd[t][m]!=0){
		return;
	}
	else{
		asd[t][m]=sum;
	}
	for(int i=t+1;i<=n;i++){
		wl(sum,a[i].su);
		sus(i,m-1,zs);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].su;
		c=a[i].su;
		int j=0;
		while(c!=0){
			j++;
			c=c>>1;
		}
		a[i].id=j;
	}
	sort(a+1,a+n+1,cmn);
	for(int i=1;i<=n+1-m;i++){
		sus(i,m,a[i].su);
	}
	cout<<ans;
	return 0;
} 
