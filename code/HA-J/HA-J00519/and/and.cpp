#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[200010];
int n,m,rez[200010][200],re[200010][200];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
	    int t=0; 
		while(a[i]>0){
			rez[i][++t]=a[i]%2;
			a[i]/=2;
		}
		for(int j=1;j<=t;j++){
			if(rez[i][j]==1&&rez[i-1][j]==1){
				re[i][j]=1;
			}
			else{
				re[i][j]=0;
			}
		} 
	}
	ll ans=0;
	for(int i=1;i<=200;i++){
		if(re[m][i]==1) ans+=pow(2,i-1);
	}
	cout<<ans;
	return 0;
}
