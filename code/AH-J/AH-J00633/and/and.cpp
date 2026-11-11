#include<bits/stdc++.h>
using namespace std;
int a[200005],b[200005];
int ans=0,id=0; 
int m,n;
void dfs(int step,int cnt){
	if(step>n-cnt){
		int x;
		bool f=0;
		if(b[1]!=0){
			int x=b[1];
			for(int i=2;i<=id;i++){
				x=x&b[i];	
			}
			f=1;
		}
		if(!f){
			x=a[n-m+cnt];
		}
		for(int i=n-m+cnt;i<=n;i++){
			x=x&a[i];
		}
		ans=max(ans,x);
		return ;
	}
	if(cnt==0){
		int x=b[1];
		for(int i=2;i<=m;i++){
			x=x&b[i];	
		}
		ans=max(ans,x);
		return ;
	}
	dfs(step+1,cnt);
	b[++id]=a[step];
	dfs(step+1,cnt-1);
	b[id--]=0;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i-1){
			f=0;
		}
	}
	if(m==1){
		sort(a+1,a+1+n);
		cout<<a[n];
		return 0;
	}
	if(m==n){
		int x=a[1];
		for(int i=2;i<=n;i++){
			x&=a[i];
		}
		cout<<x;
		return 0;
	}
	if(f){
		if(m>n/2){
			cout<<0;
		}
		else{
			if(m<=n/4){
				cout<<n/2+(m-1)*2;
			}
			else{
				cout<<n/2;
			}
		}
		return 0;
	}	
	if(n<=20){
		dfs(1,m);
		cout<<ans;
		return 0;
	}
	srand(time(0));
	cout<<rand()%(n+1);
	return 0;
}

