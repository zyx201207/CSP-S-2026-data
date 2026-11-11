#include<bits/stdc++.h>
using namespace std;
const int maxn=2e4+2334;
int n,m,a[maxn],b[maxn][maxn],c[maxn];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			b[i][j]=a[j]-a[i];
		}
	}
	for(int i=1;i<=n;i++){
		c[i]=1;
	}
	for(int j=2;j<=n;j++){
		int s=m;
		for(int i=j-1;i>=1;i--){
			if(s>=b[i][j]){
				c[j]++;
				s-=b[i][j];
			}
		}
	}
	int cnt=0;
	for(int i=2;i<=n;i++){
		cnt=max(cnt,c[i]);
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
  return 0;
} 
