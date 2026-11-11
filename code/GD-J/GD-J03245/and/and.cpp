#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,maxn=-1;
int a[3000];
bool c(int a,int b){
	return a>b;
}
void f(int x,int sum,int cnt){
	if(cnt==m){
		maxn=max(maxn,sum);
		return ;
	}	
	if(x==n+1){
		return ;
	}
	if(cnt==0){
		f(x+1,a[x],cnt+1);
	}
	else{
		f(x+1,sum&a[x],cnt+1);
	}
	f(x+1,sum,cnt);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n-1){
		sort(a+1,a+1+n,c);
		int sum=a[1];
		for(int i=2;i<=m;i++){
			sum&=a[i];
		}
		cout<<sum;
	}
	else {
		f(1,0,0);
	    cout<<maxn;
	}
	return 0;
}
