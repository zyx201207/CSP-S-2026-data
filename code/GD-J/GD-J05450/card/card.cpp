#include<bits/stdc++.h>
using namespace std;
const int N=1e5*5+10,M=1e5*3+10;
int n,m,a[N],s[M],d[M],cnt;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(cnt<n){
		cnt++;
		int ord=cnt;
		for(int i=cnt;i<=n;i++){
			for(int j=cnt;j<ord;j++){
				if(d[j]==a[i]){
					ord=j;
					break;
				}
			}
			d[ord]=a[i];
			ord++;
		}
		for(int i=cnt;i<ord;i++){
			s[d[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<' ';
	}
	return 0; 
} 
