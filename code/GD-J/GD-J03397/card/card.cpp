#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
int a[500005],c[300005],b[300005],d[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		cnt=1;
		fill(c+1,c+m+1,0);
		fill(b+1,b+m+1,0);
		for(int j=i;j<=n;j++){
			if(c[a[j]]&&c[a[j]]<cnt){
				cnt=c[a[j]];
			}
			c[a[j]]=cnt;
			b[cnt]=a[j];
			cnt++;
		}
		for(int j=1;j<cnt;j++){
			d[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<d[i]<<' ';
	}
	return 0;
}

