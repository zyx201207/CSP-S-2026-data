#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n,m,ans=0;
int a[maxn],mp[maxn][31],pw[31];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+1+n);
		cout<<a[n];
		return 0;
	}
	int maxw=0;
	for(int i=1;i<=n;i++){
		int w=0;
		while(a[i]){
			w++;
			mp[i][w]=a[i]%2;
			a[i]/=2;
		}
		maxw=max(maxw,w);
	}
	for(int i=1;i<=maxw;i++){
		pw[i]=pow(2,i-1);
	}
	for(int j=maxw;j>=1;j--){
		int s=0,flag=1;
		for(int i=1;i<=n;i++){
			if(mp[i][j]){
				s++;
			}
		}
		if(s>=m){
			ans+=pw[j];
		}
	}cout<<ans;
	fclose(stdin);
	fclose(stdout);
  return 0;
}
