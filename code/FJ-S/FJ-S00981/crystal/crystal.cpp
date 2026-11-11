#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005];
int d[500005];
int ans=-1;
int n,m;
int sum(int l,int r){
	return d[r]-d[l-1];
}
void input(int &n){
	int f=1;
	char c;
	c=getchar();
	while(!(c>='0'&&c<='9')){
		if(c=='-') f=-1;
		c=getchar();
	}
	n=0;
	while(c>='0'&&c<='9'){
		n=(n*10)+(c-'0');
		c=getchar();
	}
	n*=f;
}
void output(int n){
	if(n<0){
		putchar('-');
		n=-n;
	}
	if(n>9) output(n/10);
	putchar(n%10+'0');
}
int check(int l,int r,int len){
	if((a[r]*len)==(sum(l,r)+m)) return len;
	return -1;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	input(n);
	input(m);
	for(int i=1;i<=n;i++){
		input(a[i]);
		d[i]=d[i-1]+a[i];
	}
	sort(a+1,a+1+n);
	for(int len=1;len<=n;len++){
		for(int l=1;l+len-1<=n;l++){
			int r=l+len-1;
 			int t=check(l,r,len);
			if(t==-1) continue;
			ans=max(ans,t);
			for(int i=l;i<=r;i++) cout<<a[i]<<'\n';
		}
	}
	cout<<'\n';
	cout<<ans;

	return 0;
}

