#include <bits/stdc++.h>
using namespace std;
int a[500001];
int b[500001];
bool d[300001];
int c[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++){
		int s=0;
		for(int j=i;j<=n;j++){
			s++;
			b[s]=a[j];
			for(int z=1;z<s;z++){
				if(b[z]==b[s]){
					for(int u=z;u<=s;u++) b[u]=0;
					b[z]=a[j];
					s=z;
					break;
				}
			}
			
		}
		for(int j=1;j<=s;j++){
			d[b[j]]=1;
			b[j]=0;
		} 
		for(int j=1;j<=m;j++){
			if(d[j]){
				c[j]++;
				d[j]=0;
			} 
		}
	}
	for(int i=1;i<=m;i++) cout << c[i] << " ";
	return 0;
}
