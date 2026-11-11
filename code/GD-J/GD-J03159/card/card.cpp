#include<bits/stdc++.h>
using namespace std;
const int N=1e5*5+10,M=1e5*3+10;
int n,m;
int a[N],b[M],c[N];
int main(){
	ios::sync_with_stdio(NULL);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int p=0;
	for(int o=1;o<=n;o++){
		p=o-1;
		for(int i=o;i<=n;i++){		
			for(int j=o;j<i;j++){
				if(a[i]==a[j]){
					for(int k=j;k<i;k++){	
						p++;
						c[p]=a[k];
						a[k]=0;
					}
				}
			}
		}
		for(int j=o;j<=n;j++){
			if(a[j]!=0){
				b[a[j]]++;
				p++;
				c[p]=a[j];
			}
		}
		for(int j=o+1;j<=n;j++){
			a[j]=c[j];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<' ';
	}
	cout<<endl;
	return 0;
}
