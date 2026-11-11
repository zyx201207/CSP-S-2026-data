#include<bits/stdc++.h>
using namespace std;

const int N=500005;

typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f*=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
ll n,m; 
ll a[N];
ll cnt[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();
	m=read();
	bool pda=0,pdb=0;
	ll gc=0;
	for(int i=1;i<=n;i++){
		a[i]=read();
		
		if(a[i]!=i)pda=1;
		
		if(i==2)gc=a[i]-a[i-1];
		else if(i>2){
			if(a[i]-a[i-1]!=gc)pdb=1;
		}
	}

	//A
	if(pda==0){
		int cnt=1;
		ll tmp=m;
		for(int i=n-1;i>=1;i--){
			if(n-i<=tmp){
				cnt++;
				tmp-=(n-i);
			}else break;
		}
		cout<<cnt<<endl;
		return 0;
	}
	
	//B
	if(pdb==0){
		int cnt=1;
		ll tmp=m;
		for(int i=n-1;i>=1;i--){
			if((n-i)*gc<=tmp){
				cnt++;
				tmp-=(n-i)*gc;
			}else break;
		}
		cout<<cnt<<endl;
		return 0;
	}
	
	
	
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		ll tmp=m;
		ll j=i-1;
		while(tmp>0&&j>0){
			if(a[i]-a[j]<=tmp){
				cnt[i]++;
				tmp-=(a[i]-a[j]);
				j--;
			}else break;
		}
	}
	ll maxn=0;
	for(int i=1;i<=n;i++){
		maxn=max(maxn,cnt[i]);
	}
	cout<<maxn+1<<endl;
	return 0;
}
