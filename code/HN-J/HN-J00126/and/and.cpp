#include<bits/stdc++.h>
using namespace std;
long long n,m,sum=0,maxn=0;
long long a[300000];
long long b[300000],c[300000];
void d(int q){
	if(q>m){
		sum=a[c[1]]&a[c[2]];
		for(int i=3;i<=m;i++){
			sum=sum&a[c[i]];
		}
		maxn=max(maxn,sum);
		return ;
	}
	for(int i=c[q-1];i<=n;i++){
		if(b[i]==0){
			b[i]=1;
			c[q]=i;
			d(q+1);
			b[i]=0;
		}
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	d(1);
	cout<<maxn;

	return 0;
}

