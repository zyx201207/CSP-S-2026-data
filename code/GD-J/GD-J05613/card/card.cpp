#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int>c(n+5);
	for(int i=1;i<=n;i++) cin>>c[i];
	vector<int>t(m+5);
	for(int i=1;i<=n;i++){
		int p=1;
		vector<int> ln(m+5,0);
		vector<int>noww(n+5,0);
		int siz=1;
		for(int j=i;j<=n;j++){
			if(ln[c[j]]!=0){
				int pos=ln[c[j]];
				for(int k=p-1;k>=pos;k--){
					ln[noww[k]]=0;
					noww[--p]=0;
				}
			}
			noww[p]=c[j];
			ln[c[j]]=p;
			p++;
		}
		for(int j=1;j<=m;j++){
			if(ln[j]>0) t[j]++;
		} 
	}
	for(int i=1;i<=m;i++) cout<<t[i]<<' ';
	return 0;
}


