#include<bits/stdc++.h>

using namespace std;

int a[500005],sum[300005];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= m;i++){
		int c[300005];
		memset(c,0,sizeof c);
		for(int j = i;j <= n;j++){
			if(!c[a[j]]) c[a[j]] = j;
			else{
				for(int o = c[a[j]];o < j;o++){
					c[o] = 0;
				}
			}
		}
		for(int j = 1;j <= m;j++){
			if(c[i]) sum[i]++;
		}
	}
	for(int i = 1;i <= m;i++){
		cout<<sum[i]<<" ";
	}
}
