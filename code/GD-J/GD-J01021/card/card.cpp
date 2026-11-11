#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[1000006],b[1000006],c[1000006],d[1000006];
signed main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","r",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			cnt++;
			if(c[a[j]]!=0){
				cnt-=j-d[a[j]];
				for(int k=d[a[j]];k<j;k++){
					c[a[k]]=0;
				}
			}
			c[a[j]]++;
			d[a[j]]=cnt;
		}
		for(int j=1;j<=cnt;j++){
			if(c[a[j]]!=0)b[a[j]]++;
			c[a[j]]=0;
		}
		cnt=0;
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
} 
