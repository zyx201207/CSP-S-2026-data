#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=600000;
int a[N],b[N];
int n,m,ans=1;
int way[5][2]={{-1,0},{0,+1},{+1,+2},{-2,-1},{-1,+1}};
bool check(int p,int k){
	if(p>n||k>n||p<1||k<1){
		return false;
	}
	if(k>p) swap(k,p);
	if((p-k)*a[p]-b[p-1]+b[k-1]<=m){
		return true;
	}
	return false;
}
void dfs(int k,int p){
	if(check(k,p)){
		bool can=0;
		if(check(k-1,p+1)){
			int e=1;
			while(check(k-e,p+e)){
				e++;
			}
			e=e-1;
			ans=max(p+e-k+e+1,ans);
			dfs(k-e,p+e);
			can=1;
		}
		if(check(k,p+1)){
			int e=1;
			while(check(k,p+e)){
				e++;
			}
			e=e-1;
			ans=max(p+e-k+1,ans);
			dfs(k,p+e);
			can=1;
		}
		if(check(k-1,p)){
			int e=1;
			while(check(k-e,p)){
				e++;
			}
			e=e-1;
			ans=max(ans,p-k+e+1);
			dfs(k-e,p);
			can=1;
		}
		if(check(k-2,p-1)){
			int e=2;
			while(check(k-e,p-1)){
				e++;
			}
			e=e-1;
			ans=max(ans,p-k+e);
			dfs(k-e,p-1);
			can=1;
		}
		if(check(k+1,p+2)){
			int e=2;
			while(check(k+1,p+e)){
				e++;
			}
			e=e-1;
			ans=max(p+e-k,ans);
			dfs(k+1,p+e);
			can=1;
		}
	}
	else{
		return;
	}
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	b[1]=a[1];
	for(int i=2;i<=n;i++){
		b[i]=a[i]+b[i-1];
	}
	int k=(n+1)/2,p=k+1;
	while(!check(k,p)&&k>=1){
		k--;
		p--;
	}
	if(k==0){
		k=(n+1)/2,p=k+1;
		while(!check(k,p)&&p<=n){
			k++;
			p++;
		}
		if(p==n+1){
			cout<<1;
			return 0;
		}
	}
	dfs(k,p);
	k=(n+1)/2,p=k+1;
	while(!check(k,p)&&p<=n){
		k++;
		p++;
	}
	if(p==n+1){
		k=(n+1)/2,p=k+1;
		while(!check(k,p)&&k>=1){
		    k--;
		    p--;
	    }
		if(k==0){
			cout<<1;
			return 0;
		}
	}
	dfs(k,p);
	while(check(k,p)){
		bool flag=0;
		if(check(k-1,p)){
			int e=1;
			while(check(k-e,p)){
				e++;
			}
			e--;
			k-=e;
		}
		else if(check(k,p+1)){
			int e=1;
			while(check(k,p+e)){
				e++;
			}
			e--;
			p+=e;
		}
		else if(check(k-2,p-1)){
			int e=2;
			while(check(k-e,p-1)){
				e++;
			}
			e--;
			p--;
			k-=e;
		}
		else if(check(k+1,p+2)){
			int e=2;
			while(check(k+1,p+e)){
				e++;
			}
			e--;
			k++;
			p+=e;
		}
		else {
			break;
		}
	}
	cout<<max(ans,p-k+1)<<endl;
	return 0;
}