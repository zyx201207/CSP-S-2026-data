#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;

long long n,m;
long long ans=pow(2,30)-1;

struct node{
	int num,cont;
}a[N];

int check(long long x){
	int cnt=0;
	while(x){
		if(x&1)cnt++;
		x=x>>1;
	}
	return cnt;
}

bool cmp(node x,node y){
	if(x.cont==y.cont)return x.num>y.num;
	return x.cont>y.cont;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].num;
		a[i].cont=check(a[i].num);
	}
	
	sort(a+1,a+n+1,cmp);
	
	int step=0;
	for(int i=1;i<=n&&step<m;i++){
		ans&=a[i].num;
		step++;
	}
	
	cout<<ans;
	
	return 0;
}
