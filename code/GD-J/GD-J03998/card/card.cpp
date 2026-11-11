#include<bits/stdc++.h>
using namespace std;
int n,m,i,j;
int a[500010],book[500010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	i=0;
	while(i<n){
		int p=i,o=i+1;
		i++;
		for(;i<=n;i++){
			for(j=o;j<i;j++){
				if(a[i]==a[j]){
					o=i;
					break;
				}
			}
		}
		for(;o<=n;o++)book[a[o]]++;
		i=p+1;
	}
	for(int i=1;i<=m;i++)cout<<book[i]<<' ';
	return 0;
}
