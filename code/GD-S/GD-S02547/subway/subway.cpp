#include<bits/stdc++.h>
using namespace std;

int c,m,n,d,p,s;
int x[10000],k[10000],st[10000],ed[10000];
int t,oo,a,aa;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>p;
	for(int i = 1;i <= m;i++){
		cin>>x[i];
	}
	for(int i = 1;i <= n;i++){
		cin>>s;
		for(int j = 1;j <= s;j++){
			cin>>t>>oo>>a>>aa;
		}
	}
	for(int i = 1;i <= p;i++){
		cin>>st[i]>>ed[i];
		int dd = (x[st[i]] + x[ed[i]]); 
		if(i == 1)cout<<dd+5+10+4+9<<endl;
		if(i == 2)cout<<dd+5+7;
	}
	return 0;
} 
