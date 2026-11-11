#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[3000500];
int b[3000500];
int c[3000500];
int d[3000500];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int l=0;
		for(int j=i;j<=n;j++){
			if(c[a[j]]==0){
				l++;
				c[a[j]]=l;
				d[l]=a[j];
			}
			else{
				for(int z=c[a[j]]+1;z<=l;z++){
					c[d[z]]=0;
					d[z]=0;
				}
				l=c[a[j]];
			}
		}
		for(int p=1;p<=l;p++){
			b[d[p]]++;
		}
		l=0;
		memset(c,0,sizeof(c));
		memset(d,0,sizeof(d));
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
