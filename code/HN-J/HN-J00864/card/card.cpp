#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],t[500005],b[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int num = m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	int cnt = 0;
	while(m--){
		memset(b,0,sizeof b);
		for(int i = cnt;i <= n;i++){
			for(int j = 1;j <= i-1;j++){
				if(b[j] == a[i]){
					for(int k = j;k <= i-1;k++){
						b[k] = 0;
					}
					break;
				}
			}
			b[i] = a[i];
		}
		for(int i = 1;i <= n;i++){
			t[b[i]]++;
		}
		cnt++;
	}
	for(int i = 1;i <= num;i++){
		cout<<t[i]<<" ";
	}
	return 0;
} 
