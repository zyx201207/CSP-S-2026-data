#include<bits/stdc++.h>
using namespace std;
long long n,q[300010],m,o,p,s,l,w[300010];
long long dfs(long long a,long long k){
	if(a>m){
		s=max(k,s);
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(!w[i]){
			w[i]=1;
			if(a==1){
				k=q[i];
			}
			dfs(a+1,k&q[i]);
			w[i]=0;
		}
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>q[i];
		l=max(l,q[i]);
	}
	if(m==n){
		s=q[1];
		for(int i=2;i<=n;i++){
			s=s&q[i];
		}
		cout<<s;
	}
	else if(m==1){
		for(int i=1;i<=n;i++){
			s=max(s,q[i]);
		}
		cout<<s;
	}
	else if(m==n-1){
		sort(q+1,q+1+n);
		s=q[2];
		for(int i=3;i<=n;i++){
			s=s&q[i];
		}
		cout<<s;
	}
	else if(l<7){
		sort(q+1,q+1+n);
		s=q[n];
		for(int i=n-1;i>=n-m;i--){
			s=s&q[i];
		}
		cout<<s;
	}
	else if(m>=2&&m<n-1){
		if(n>10000&&m>2){
			sort(q+1,q+1+n);
			s=q[n];
			for(int i=n-1;i>=n-m;i--){
				s=s&q[i];
			}
			cout<<s;
		}
		else{
			sort(q+1,q+1+n);
			dfs(1,0);
			cout<<s;
		}
	}
	
	return 0;
}
