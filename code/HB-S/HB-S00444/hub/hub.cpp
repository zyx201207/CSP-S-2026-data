#include<bits/stdc++.h>
using namespace std;
long long x[1000000],d,ans=0;
int dfs(int q,int z){
	if(x[z]-x[q]<=d){
		cout << 'a';
		return 1;
	}
	int i=q+1,h=100000,hi=1;
	while(x[i]-x[q]<d&&i<z){
		int n=dfs(x[i],x[z]);
		if(h>n){
			h=n;
			hi=1;
		}
		else if(n==h){
			hi++;
		}
		i++;
	}
	if(hi==2){
		ans++;
	}
	return h+1;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int  c,t;
	cin >> c >> t;
	for(int a=0;a<t;a++){
		int n;
		cin >> n >> d;
		for(int i=0;i<n;i++){
			cin >> x[i];
		}
		int ans=0;
		for(int i=0;i<n;i++){
			dfs(i,n-1);
		}
		cout << ans << endl;
	}
}
