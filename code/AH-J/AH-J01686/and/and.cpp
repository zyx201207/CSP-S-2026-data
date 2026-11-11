#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[200005][35];
bool b[200005];
int c[35];
int maxn;
int ans;

void fun(int i,int x){
	int j=0;
	while(x>0){
		a[i][j]=x%2;
		x=x/2;
		j++;
	}
	maxn=max(maxn,j-1);
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		fun(i,x);
	}
	
	
	c[0]=1;
	for(int i=1;i<=31;i++)
		c[i]=c[i-1]*2;
		
		
	for(int i=maxn;i>=0;i--){
		int s=0;
		for(int j=1;j<=n;j++){
			if(a[j][i]==1&&b[j]==0)
				s++;
		}
		if(s>=m){
			ans+=c[i];
			for(int j=1;j<=n;j++){
				if(a[j][i]==0)
					b[j]=1;
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}
