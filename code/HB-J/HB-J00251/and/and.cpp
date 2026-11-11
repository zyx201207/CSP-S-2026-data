#include<bits/stdc++.h>
using namespace std;

int n,m,ma=-1,he,p=1;
int a[200086],ans=-1;
int gre_zhi[]={0,1,1,2,0};

bool zh(double k){
	return k==int(k);
}
bool cmp(int x,int y){
	return gre_zhi[x]>gre_zhi[y];
}

void dfs(int x,int cur,int idx){
	if(x==m+1){
		ans=max(ans,cur);
		return;
	}
	
	for(int i=idx+1;i<=n+1;i++){
		dfs(x+1,cur&a[i],i);
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
		
		if(i==1)he=a[i];
		else he&=a[i];
		
		if(p==1&&!zh(log2(a[i]+1)))p=0;
	}a[n+1]=INT_MAX;
		
	if(n<=20||m==2){//bao li +20 or 30
		dfs(0,INT_MAX,0);
		cout<<ans;
		return 0;
	}
	if(m==1){
		cout<<ma;
		return 0;
	}
	else if(m==n){
		cout<<he;
		return 0;
	}
	else if(m==n-1){ // fan xiang bao li
		for(int i=1;i<=n;i++){
			int sum=INT_MAX;
			for(int j=1;j<=n;j++){
				if(j!=i)sum&=a[j];
			}
			ans=max(ans,sum);
		}
		cout<<ans;
		return 0;
	}
	else if(p){
		sort(a+1,a+n+1,less<int>());
		cout<<a[n-m+1];
		return 0;
	}
	else if(ma<=4){
		int sum=INT_MAX;
		
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=m;i++){
			sum&=a[i];
		}
		cout<<sum;
		return 0;
	}
	else{ //tan tan?!
		dfs(0,INT_MAX,0);
		cout<<ans;
	}
	
	
	return 0;
}
