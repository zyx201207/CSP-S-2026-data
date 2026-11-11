#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],k[100005],t=0,d[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int c=1;c<=t;c++){
				if(k[c]==a[j]){
					for(int h=c;h<=t;h++){
						k[h]=0;
					}
					t-=t-c-1;
				}
			}
			k[++t]=a[j];
		}
		for(int c=1;c<=t;c++){
			d[k[c]]++;
		}
		memset(k,0,sizeof(k));
		t=0;
	}
	for(int i=1;i<=m;i++){
		cout<<d[i]<<" ";
	}
	return 0;
}

