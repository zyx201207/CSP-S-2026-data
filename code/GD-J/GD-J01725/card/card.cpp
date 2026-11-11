#include <bits/stdc++.h>
using namespace std;
int a[200010][2],b[200010],n,m,l,r,t[200010];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i][0];
	for(int i=1;i<=n;i++){
		l=1;
		r=1;
		for(int j=i;j<=n;j++){
			b[r]=a[j][0];
			for(int ll=l;ll<r;ll++){
				if(b[ll]==b[r] && ll!=r){
					r=ll;
					break;			
				}
			}r++;
		}
		for(int k=l;k<=r-1;k++){
			t[b[k]]++;
		}
	}for(int i=1;i<=m;i++){
		cout<<t[i]<<' ';
	}
	return 0;
}
