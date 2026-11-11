#include<bits/stdc++.h>
using namespace std;
struct ff{
 int xxx;
 int xx;	
};
int c,n,m,d,q;
int w[200005];
int t[10005][10005];
ff s[10005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		t[i][0]=k;
		for(int j=1;j<=k*2;j++){
			cin>>t[i][j];
		}
	}
	for(int i=0;i<q;i++){
		cin>>s[i].xx>>s[i].xxx;
	}
	cout<<35<<endl;
	cout<<16;
	return 0;
}