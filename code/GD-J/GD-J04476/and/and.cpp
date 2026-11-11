#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll rd(){
	ll sign=1,res=0;char c=getchar();
	while(!isdigit(c)){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(isdigit(c)){
		res=res*10+c-'0';
		c=getchar();
	}
	return sign*res;
}
const int N=2e5+5;
int n,m;
int a[N];
int ans,ans1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	n=rd(),m=rd();
	for(int i=1;i<=n;i++){
		a[i]=rd(); 
	}
	ans=a[1];
	for(int i=2;i<=m;i++){
		ans&=a[i];
	}
	
	sort(a+1,a+n+1,greater<int>());
	int k=log2(a[m]);
	k=(1<<k+1)-1;
	for(int i=1;i<=n;i++) a[i]&=k;
	sort(a+1,a+n+1,greater<int>());
	ans1=a[1];
	for(int i=2;i<=m;i++){
		ans1&=a[i];
	}
	
	cout<<max(ans,ans1)<<"\n";
	return 0;
}

