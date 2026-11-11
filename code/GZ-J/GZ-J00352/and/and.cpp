//GZ-J00352 遵义市第四中学  罗永淇 
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct nod{
	int k,s;
}a[N];
int jd(int x){
	int tt=0;
	while(x){
		int y=x%2;
		if(y==1) tt++;
		x/=2;
	}
	return tt;
}
bool cmp(nod x,nod y){
	if(x.k>y.k){
		return x.k;
	}
	else{
		return x.s>y.s;
	}
}
int main(){
	freopen("and","r",stdin);
	freopen("and","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].k;
		a[i].s=jd(a[i].k);
	}
	sort(a+1,a+1+n,cmp);
	int k,t=0;
	for(int i=1;i<=n;i++){
		int x=log2(a[i]),y=log2(a[i-1]);
		k=a[i]&a[i-1];
		t++;
		if(t==m) break;
	}
	cout<<k;
	return 0;
}
