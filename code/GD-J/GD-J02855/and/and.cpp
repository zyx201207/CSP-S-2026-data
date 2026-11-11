#include<bits/stdc++.h>
#define t long long
#define ll unsigned long long
using namespace std;
t n,a[200005],m,ans,c,d[200005],maxa,a1,a2,a3,u=2147483647;
string s;
void dfs(t i,t sum,t cr){
	if(i==m+1){
		ans=max(ans,sum);
		return;
	}
	for(t j=cr;j<=n;j++){
		dfs(i+1,sum&a[j],j+1);
	}
}
int main(int argc,char** argv)
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m==n){
		cin>>a[1];
		for(t i=2;i<=n;i++){
			cin>>a[i];
			a[1]&=a[i];
		}
		cout<<a[1],exit(0);
	}
	if(m==n-1){
		for(t i=1;i<=n;i++){
			a[i]=2147483647;
		}
		for(t i=1;i<=n;i++){
			cin>>c;
		}
	}
	bool p=0,q=0;
	for(t i=1;i<=n;i++){
		cin>>a[i];
		maxa=max(maxa,a[i]);
		if(a[i]==1)a1++;
		if(a[i]==2)a2++;
		if(a[i]==3)a3++;
		if(a[i]&u!=a[i])p=1;
		if(a[i]!=i-1)q=1;
	}
	if(p==0){
		sort(a+1,a+1+n,greater<t>());
		cout<<a[m],exit(0);
	}
	if(q==0){
		t sum=0;
		while(n/=2){
			if(m>n)cout<<sum,exit(0);
			sum+=n;
			
		}
		cout<<sum,exit(0);
	}
	if(m==1)cout<<maxa,exit(0);
	if(maxa<4){
		if(a3>=m)cout<<3,exit(0);
		if(a3+a2>=m)cout<<2,exit(0);
		if(a3+a1>=m)cout<<1,exit(0);
		cout<<0,exit(0);
	}
	dfs(1,2147483647,1);
	cout<<ans;
}
//按位与只会越来越小
//29 14 7 3 1
