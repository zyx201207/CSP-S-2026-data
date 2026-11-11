#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000005],s[1000005],om;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			om=1;
			for(int k=j+1;k<=n;k++){
				if(a[j]==a[k]){
					j=k-1;
					om=0;
					break;
				}
			}if(om)s[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<s[i]<<' ';
	return 0;
}
