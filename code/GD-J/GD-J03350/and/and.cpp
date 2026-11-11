#include<bits/stdc++.h>
using namespace std;

int check(int a){
	int as=0; 
	int p=10;
	while(a){
		int r=a%2;
		as=as+r*p;
		a/=2;
		p*=10;
	} 
	return as;
}

int f(int a,int b){
	int as=check(a);
	int bs=check(b);
	int c=0;
	while(a && b){
		if(a%10==b%10) c=c*10+1;
		else c=c*10+0;
		a/=10;
		b/=10;
	}
	int p=1;
	int ans;
	while(c){
		int r=c%10;
		ans+=r*p;
		p*=2;
		c/=10;
	}
	return ans;
} 

int main(){
	freopen("ans.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m; cin>>n>>m;
	int a[n];
	int ans=0,cnt;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n-m;i++){
		cnt=a[i];
		for(int x=i;x<i+m;x++){
			cnt=f(cnt,a[x]);
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
} 
