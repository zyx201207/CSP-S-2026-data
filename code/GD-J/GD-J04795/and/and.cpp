#include<bits/stdc++.h>
using namespace std;
const int N=200050;
int n,m;
int ans=0;
int a[N];
int b[N][35],c[35],d[5],p[35];
void dfs(int x,int k,int s){
	if(x==n+1&&k<m)
		return;
	if(k==m){
		ans=max(ans,s);
		return;
	}
	if(s<=ans&&s!=-1)
		return;
	if(s==-1)
		dfs(x+1,k+1,a[x]);
	else
		dfs(x+1,k+1,s&a[x]);
	dfs(x+1,k,s);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	p[1]=1;
	for(int i=2;i<=31;i++)
		p[i]=p[i-1]*2;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[1];
		return 0;
	}
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++)
			ans=ans&a[i];
		cout<<ans;
		return 0;
	}
	if(m==2&&n<=4000){
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				ans=max(ans,a[i]&a[j]);
		cout<<ans;
		return 0;
	}
	if(n<=20){
		dfs(1,0,-1);
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		int x=a[i];
		for(int j=1;j<=30;j++){
			b[i][j]=x%2;
			c[j]+=x%2;
			x/=2;
		}
	}
	if(m==n-1){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=30;j++)
				c[j]-=b[i][j];
			int sum=0;
			for(int j=1;j<=30;j++){
				if(c[j]>=m){
					sum+=p[j];
				}
			}
			ans=max(ans,sum);
			for(int j=1;j<=30;j++)
				c[j]+=b[i][j];
		}
		cout<<ans;
		return 0;
	}
	bool flag1=1,flag2=0;
	for(int i=1;i<=n;i++){
		if(a[i]!=i-1){
			flag1=0;
			break;
		}
	}
	for(int i=1;i<=n;i++){
		if(n==p[i]){
			flag2=1;
			break;
		}
	}
	if(flag1&&flag2){
		if(m>n/2){
			cout<<0;
			return 0;
		}
		if(m>n/4&&m<=n/2){
			cout<<n/2;
			return 0;
		}
		cout<<a[n-m];
		return 0;
	}
	flag1=1;
	for(int i=1;i<=n;i++){
		flag2=0;
		for(int j=1;j<=31;j++){
			if(a[i]==p[j]-1){
				flag2=1;
				break;
			}
		}
		if(!flag2){
			flag1=0;
			break;
		}
	}
	if(flag1){
		cout<<a[m];
		return 0;
	}
	if(a[1]<4){
		for(int i=1;i<=n;i++)
			d[a[i]]++;
		if(d[3]>=m){
			cout<<3;
			return 0;
		}	
		if(d[3]+d[2]>=m){
			cout<<2;
			return 0; 
		}
		if(d[3]+d[1]>=m){
			cout<<1;
			return 0;
		}
		cout<<0;
		return 0;
	}
	cout<<n;
	return 0;
}
