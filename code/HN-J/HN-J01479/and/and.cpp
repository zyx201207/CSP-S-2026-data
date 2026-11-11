#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100005],b,c;
int cmp(int x,int y){
	return x>y;
}

int p(int x,int y){
	int l,k=0;
	if(x==y){
		return x;
	}
	for(int i=2;i<=x;i=i*2){
		l=i;
	}
	for(int i=l;i>=1;i=i/2){
		if(x>=i and y>=i){
			x-=i;
			y-=i;
			k+=i;
		}
		else if(x>=i){
			x-=i;
		}
		else if(y>=i){
			y-=i;
		}
	}
	return k;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c=max(c,a[i]);
	}
	sort(a+1,a+n+1,cmp);
	if(m==1){
		cout<<c;
		return 0;
	}
	b=a[1];
	for(int i=2;i<=m;i++){
		b=p(b,a[i]);
	}
	cout<<b;
	return 0;
}
