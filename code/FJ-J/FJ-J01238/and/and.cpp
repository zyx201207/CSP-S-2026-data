#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans,amax,lf=1,t;
int l[100005][25];
bool b[200005];
void dfs(int k){
	for(int i=1;i<=n;i++){
		if(b[i]==0&&i>l[lf][k-1]){
			l[lf][k]=i;
			b[i]=1;
			if(k==m){
				for(int i=1;i<=m;i++){
					l[lf+1][i]=l[lf][i];
				}
				lf++;
			}else{
				dfs(k+1);
			}
		}
		b[i]=0;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		amax=max(amax,a[i]);
	}
	if(m==1){
		cout<<amax;
		exit(0);
	}
	if(m==n){
		for(int i=2;i<=n;i++){
			ans=a[i]&a[i-1];
		}
		cout<<ans;
		exit(0);
	}
	if(m==2){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		exit(0);
	}if(n<=2000){
		dfs(1);
		for(int i=1;i<lf;i++){
			t=a[l[i][1]];
			for(int j=2;j<=m;j++){
				t=t&a[l[i][j]];
			}
			ans=max(ans,t);
		}
		cout<<ans;
		exit(0);
	}if(n>2000){
		cout<<amax;
	}
	return 0;
}
