#include<bits/stdc++.h>
using namespace std;
int m,n,num,t;
long long a[500005],g[500005],gt;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n-1;i++){
		for(int j=i;j<n;j++){
			g[gt++]=a[j];
			for(int gc=0;gc<gt-1;gc++){
				if(g[gt-1]==g[gc]){
					for(int gs=gc;gc<gt-1;gs++){
						g[gs]=0;
					}
					gt=gc;
					g[gc]=a[j];
					break;
				}
			}
		}
		for(int i=0;i<gt;i++){
			if(g[i]==i) num++;
		}
		cout<<num<<endl;
	}
	return 0;
}
