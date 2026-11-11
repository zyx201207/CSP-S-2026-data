#include <bits/stdc++.h>
using namespace std;
int n,m;
int x[500005],y[500005],z[300005],t[300005];
bool a[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> x[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			y[j]=x[j];
		}
		for(int j=1;j<i;j++){
			y[j]=0;
		}
		for(int j=1;j<=n;j++){
			if(a[y[j]]==1){
				for(int s=z[y[j]];s<j;s++){
					y[s]=0;
					a[y[s]]=0;
				}
				a[y[j]]=1;
				z[y[j]]=j;
			}
			a[y[j]]=1;
			z[y[j]]=j;
		}
		for(int j=1;j<=m;j++){
			if(a[j]==1){
				t[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout << t[1] << ' ';
	}
	
	return 0;
} 
