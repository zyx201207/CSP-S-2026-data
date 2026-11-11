#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010][40],b[200010],c[40];
int ans[40];
bool f[200010],f1[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int x,maxn=0;
	for(int i=1;i<=n;i++){
		cin>>x;
		int cnt=0;
		while(x!=0){
			a[i][++cnt]=x%2;
			x/=2;
		}
		b[i]=cnt;
		maxn=max(maxn,cnt);
	}
	for(int i=1;i<=maxn;i++){
		for(int j=1;j<=n;j++){
			if(a[j][i]==1) c[i]++;
		}
	}
	bool flag=false;
	for(int i=maxn;i>=1;i--){
		if(c[i]>=m&&flag==false){
			for(int j=1;j<=n;j++){
				if(a[j][i]==1) f[j]=1;
			}
			ans[i]=1;
			flag=true;
		}
		else if(c[i]>=m&&flag==true){
			int cnt1=0;
			for(int j=1;j<=n;j++){
				f1[j]=f[j];
				if(a[j][i]==0) f1[j]=0;
				else if(a[j][i]==1&&f1[j]==1) cnt1++;
			}
			if(cnt1>=m){
				for(int j=1;j<=n;j++) f[j]=f1[j];
				ans[i]=1;
			}
		}
	}
	unsigned long long maxnans=0,k=1;
	for(int i=1;i<=maxn;i++){
		maxnans+=k*ans[i];
		k*=2;
	}
	cout<<maxnans<<endl;
	return 0;
}
