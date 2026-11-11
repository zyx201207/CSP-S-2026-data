#include <bits/stdc++.h>
using namespace std;
int s[200005];
int judge(int x,int y){
	int a1[35]={},a2[35]={},b1[35]={},b2[35]={};
	int kx=0,ky=0;
	int lx=0,ly=0;
	while(x){
		a1[++kx]=x%2;
		x/=2;
		lx++;
	}
	while(y){
		b1[++ky]=y%2;
		y/=2;
		ly++;
	}
	int l=max(lx,ly),c[35]={};
	for(int i=1;i<=lx;i++) a2[i]=a1[l-i+1];
	for(int i=1;i<=ly;i++) b2[i]=b1[l-i+1];
	bool f=false;
	for(int i=1;i<=l;i++){
		if(a2[i]==1 && b2[i]==1){
			c[i]=1;
		}
		else c[i]=0;
	}
	int ans=0;
	int k=0;
	for(int i=l;i>=1;i--){
		if(c[i]==1){
			if(f==false) f=true;
			ans+=pow(2,k++);
		}
		else{
			if(f==true) k++;
			ans+=0;
		}
	}
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int maxn=-1;
	for(int i=1;i<=n;i++) cin>>s[i];
	if(n==1){
		for(int i=1;i<=n;i++) maxn=max(s[i],maxn);
		cout<<maxn;
		return 0;
	}
	else if(n==2){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				maxn=max(maxn,judge(s[i],s[j]));
			}
		}
		cout<<maxn;
		return 0;
	}
	else if(n==m){
		maxn=judge(s[1],s[2]);
		for(int i=3;i<=n;i++) maxn=judge(maxn,s[i]);
		cout<<maxn;
		return 0;
	}
	else if(n==m+1){
		int cnt=s[1];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j) cnt=judge(cnt,s[j]);
			}
			maxn=max(cnt,maxn);
		}
	}
	else{
		sort(s+1,s+n+1);
		cout<<s[0];
		return 0;
	return 0;
}
