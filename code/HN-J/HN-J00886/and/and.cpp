#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int b[200005][35],c[35],i=0,maxn=0;
int f(int x){
	int j=0,c[35];
	i++;
	while(x!=0){
		j++;
		c[j]=x%2;
		x/=2;
	}
	for(int w=1;w<=j;w++)
	b[i][w]=c[j-w+1];
	maxn=max(maxn,j);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	for(int i=1;i<=30;i++) c[i]=1;
	int n,m,ans=0,ww=0;
	long long x;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,1+a+n);
	for(int i=1;i<=n/2;i++){
		swap(a[i],a[n-i+1]);
	}
	for(int i=1;i<=m;i++){
		f(a[i]);
	}
	if(m>1){
		for(int i=1;i<=maxn-1;i++){
			if(b[1][i]==0||b[1][i+1]==0) c[i]=0;
			else c[i]=1;
		}
		for(int i=2;i<=m;i++){
			for(int j=1;j<=maxn;j++){
				if(c[j]==0||b[i][j]==0) c[i]=0;
				else c[i]=1;
				ans+=c[i]*pow(2,x);
				x++;
			}
		}
		cout<<x;
	}
	else cout<<a[1];
	
	return 0;
}
