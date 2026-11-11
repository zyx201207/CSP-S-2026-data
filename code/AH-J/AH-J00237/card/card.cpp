#include <bits/stdc++.h>
using namespace std;
int n,m,b,a[500005],s[500005],c[500005],res[500005];//smap,awhether
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<n;j++){
			s[j]=0;
			a[j]=0;
			}
		for(int k=i;k<=n;k++){
				b=c[k];
				if(a[b]==1){
				for(int j=k;true;j--){
					if(s[j]==b){
						s[j]=0;
						break;
					}
					s[j]=0;
					a[s[j]] = 0;
				}
			}
			a[b]=1;
			s[k]=b;
			}
		sort(s,s+n-i);
		for(int j=1;j<=n;j++){
			res[s[j]]++;
			
		}
		
	}
	for(int i=1;i<=m;i++){
		cout<<res[i]<<' ';
		}
	return 0;
}
