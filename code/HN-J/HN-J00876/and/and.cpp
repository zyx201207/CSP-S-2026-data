#include<bits/stdc++.h>
using namespace std;
long long max_a=0;
long long n,m,a[200005],b[200005],c[200005];
void a_max(int x){
	if(x==m+1){
	long long num=b[1];
		for(int i=2;i<x;i++){
			num&=b[i];
		}
		max_a=max(max_a,num);
	}
	for(int i=1;i<=n;i++){
		if(c[i]!=1){
			c[i]=1;
			b[x]=a[i];
			a_max(x+1);
			c[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	a_max(1);
	cout<<max_a;
	return 0;
}
