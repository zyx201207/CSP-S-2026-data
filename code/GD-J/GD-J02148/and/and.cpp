#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,js=0;
string a[200005];
int x[200005];
int y[50];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		
	}
	sort(x+1,x+n+1);
	for(int i=1;i<=n;i++){
		while(x[i]){
			int t=x[i]%2;
			t+='0';
			a[i]+=t;
			x[i]/=2;
		}
	}
	for(int i=n-m+1;i<=n;i++){
		for(int j=0;j<a[i].size();j++){
			if(a[i][j]=='1'){
				y[j]++;
			}
		}
	}
	int s=1;
	for(int i=1;i<=50;i++){
		if(y[i]>1){
			js+=s;
		}
		s*=2;
	}
	cout<<js;
	return 0;
}
