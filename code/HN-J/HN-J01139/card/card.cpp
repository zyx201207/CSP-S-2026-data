#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n + 10],b[n + 10] = {},c[n + 10] = {},d[500010] = {};
	for(int i = 1;i <= n;i++)cin>>a[i];
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
			b[j] = a[j];
			if(c[a[j]] == 1){
				int sf = 0;
				for(int k = 1;k <= n;k++){
					if(b[k] == a[j]) sf = k;
				}
				for(int k = sf + 1;k <= n;k++){
					b[k] = 0;
				}
			}
			c[a[j]] = 1;
		}
		for(int j = i;j <= n;j++){
			d[b[j]]++;
		}
		for(int j = 0;j <= n;j++)c[j] = 0;
		for(int j = 0;j <= n;j++)b[j] = 0;
	}
	for(int i = 1;i <= m;i++){
		cout<<d[m]<<" ";
	}
	return 0;
} 
