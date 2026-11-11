#include<bits/stdc++.h>
using namespace std;
int n,m;
struct card{
	string s;
	int x;
}g[110000];
int a[110000],s[110000];
int main(){
	freopen("card.in","r",stdin); 
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	g[0].s=' ';
	for(int k=1;k<=n;k++){
		cout<<k<<":"<<endl;
		for(int i=k;i<=n;i++){
			int cc=1,wz=-1;
			for(int j=0;j<=g[i-1].s.size();j++){
				if(g[i-1].s[j]==a[i]+'0'){
					cc=0;wz=j;
				}
			}
			char inserts=a[i]+'0';
			if(cc==0) g[i].s=inserts;
			else g[i].s=g[i-1].s+inserts;
			cout<<g[i].s<<endl;
		}
		for(int j=0;j<=g[n].s.size();j++){
			s[g[n].s[j]-'0']++;
		}
		for(int i=1;i<=n;i++){
			g[i].s=' ';
		}
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
/*
4 3
1 2 1 3
*/

