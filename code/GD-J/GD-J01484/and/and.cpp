#include<bits/stdc++.h>
using namespace std;

const int N=200005;
int n,m,ans=0;
long long a[N];
int b;

int two(int x) {
	int w=0,tot=1;
	while(x!=0) {
		int y=x%2;
		w+=tot*y;
		tot*=10;
		x/=2;
	}
	return w;
}

int k(int i,int j) {
	int x=a[i],y=a[j];
	int tot=0;
	while(x!=0&&y!=0) {
		if(x%10==y%10) tot++;
		x/=10;
		y/=10;
	}
	return tot;
}

int k2(int i,int j) {
	int x=i,y=j;
	int tot=1;
	int w=0;
	while(x!=0&&y!=0) {
		if(x%10==y%10) w+=1*tot;
		else w+=0*tot;
		tot*=10;
		x/=10;
		y/=10;
	}
	return w;
}

void work(int x) {
	int tot=2;
	int w=0;
	while(x!=0) {
		w+=x%10;
		x=x/10;
		x*=tot;
	}
	cout<<w;
	return;
}

signed main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		int x;
		cin>>x;
		a[i]=two(x);
	}
	sort(a+1,a+n+1);
	ans=a[n];
	int i=1,t=1;
	while(i<m) {
		int val=k(n-i,n);
		if(val!=0) {
			ans=k2(ans,a[n-i]);
			i++;
		}
		t++;
		if(t==n) break;
	}
	work(ans);
	return 0;
} 

/*
4 2
3 15 12 12
*/
