#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[200005];
int ans=0;
int cnt[50];
int f[50];

void dfs(int pos,int num,int sum){
	if(pos==n+1){
		if(num==m) ans=max(ans,sum);
		return;
	}
	
	dfs(pos+1,num,sum);
	if(num==0) dfs(pos+1,num+1,a[pos]);
	else dfs(pos+1,num+1,sum&a[pos]);
}

int cmp(int x,int y){
	return x>y;
}

bool checka(){
	for(int i=1;i<=n;i++){
		int x=a[i];
		while(x){
			if(x%2==0) return false;
			x/=2;
		}
	}
	return true;
}

bool checkb(){
	int x=n;
	while(x){
		if(x%2==0) return false;
		x/=2;
	}
	
	for(int i=1;i<=n;i++){
		if(a[i]!=i-1) return false;
	}
	return true;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	if(n<=20){
		dfs(1,0,0);
		cout<<ans<<endl;
		return 0;
	}
	
	if(m==1){
		sort(a+1,a+n+1,cmp);
		cout<<a[1]<<endl;
		return 0;
	}
	
	
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j) ans=max(ans,(a[i]&a[j]));
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	
	f[0]=1;
	for(int i=1;i<=30;i++) f[i]=f[i-1]*2;
	
	if(m==n-1){
		int s=a[1];
		for(int i=2;i<=n;i++) s=s&a[i];
		
		for(int i=1;i<=n;i++){
			int x=a[i],t=0;
			while(x){
				if(x%2==1) cnt[t]++;
				x/=2;
				t++;
			}
		}
		
		for(int i=1;i<=n;i++){
			int x=a[i],t=0;
			int now=s;
			while(x){
				if(x%2==0)
					if(cnt[t]==n-1) now+=f[t];
				x/=2;
				t++;
			}
			ans=max(ans,f[t]);
		}
		cout<<ans<<endl;
	}
	
	if(checka()){
		sort(a+1,a+n+1,cmp);
		cout<<a[m]<<endl;
		return 0;
	}
	
	if(checkb()){
		int x=n,k=0;
		while(x){
			k++;
			x/=2;
		}
		if(k>=m) cout<<f[k-m+1]-1<<endl;
		else cout<<0<<endl;
		return 0;
	}
	cout<<0<<endl;
	return 0;
}
