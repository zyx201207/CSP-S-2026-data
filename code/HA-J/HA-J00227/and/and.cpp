#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200010];
int f[2010][2010];
int tot[200010];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		for(int i=0;i<=n;i++){
			f[i][0]=2147483647;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				for(int k=0;k<i;k++){
					f[i][j]=max(f[i][j],f[k][j-1]&a[i]);
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			ans=max(ans,f[i][m]);
		}
		cout<<ans;
		return 0;
	}
	else if(n<=2000){
		if(m==1){
			int maxx=0;
			for(int i=1;i<=n;i++){
				maxx=max(maxx,a[i]);
			}
			cout<<maxx;
		}
		else if(n==m){
			int sum=a[1];
			for(int i=2;i<=n;i++){
				sum&=a[i];
			}
			cout<<sum;
		}
		else if(m==2){
			int maxx=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					maxx=max(maxx,a[i]&a[j]);
				}
			}
			cout<<maxx;
		}
		return 0;
	}
	bool flag4=1;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(a[i]>4){
			flag4=false;
			break;
		}
	}
	if(!flag4){
		bool lin=true;
		for(int i=1;i<=n;i++){
			if(a[i]!=i-1){
				lin=false;
				break;
			}
		}
		if(!lin){
			cout<<a[m];
			return 0;
		}
		int ans=a[n];
		for(int i=n;i>=n-m+1;i--){
			ans&=a[n];
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		tot[a[i]]++;
	}
	int ans=0;
	if(tot[4]>=m){
		ans=4;
	}
	else if(tot[3]+tot[2]>=m){
		if(tot[3]>=m){
			ans=3;
		}
		else{
			ans=2;
		}
	}
	else if(tot[1]>=m){
		ans=1;
	}
	else{
		ans=0;
	}
	cout<<ans;
	return 0;
}
