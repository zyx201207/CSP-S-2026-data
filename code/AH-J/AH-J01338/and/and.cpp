#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int ans=0;
void dfs(int l,int cnt,int h){
	if(h==m-1){
		ans=max(ans,cnt);
		return ;
	}
	if(l<1){
		return ;
	}
	dfs(l-1,cnt&a[l],h+1);
	dfs(l-1,cnt,h);
}
bool check(int N){
	bool k=1;
	while(n>1){
		if(n%2==1){
			k=0;
		}
		n/=2;
	}
	return k;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	if(m==n){
		cout<<a[1];
		return 0;
    }
    if(m==n-1){
    	cout<<a[2];
    	return 0;
	}
	if(m==2){
		ans=a[n]&a[n-1];
		cout<<ans;
		return 0;
	}
	if(n<=20){
		dfs(n-1,a[n],0);
		cout<<ans;
		return 0;
	}
	bool ok=1;
	for(int i=1;i<=n;i++){
		if(a[i]>4){
			ok=0;
		}
	}
	if(ok){
		int n1=0,n2=0,n3=0;
		for(int i=1;i<=n;i++){
			if(a[i]==3){
				n3++;
			}
			if(a[i]==2){
				n2++;
			}
			if(a[i]==1){
				n1++;
			}
		}
		if(n3>=m){
			cout<<3;
			return 0;
		}
		if(n2+n3>=m){
			cout<<2;
			return 0;
		}
		if(n1+n2+n3>=m){
			cout<<1;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}
	if(check(n)){
		cout<<a[n-m+1];
		return 0;
	}else{
		cout<<a[n-m+1];
		return 0;
	}
	int ans=a[n];
	for(int i=n-1;i>=1;i--){
		ans=ans&a[i];
	}
	cout<<ans;
	return 0;
}
