#include<bits/stdc++.h>
using namespace std;
int a[50001];
int b[50001];// 出现次数 
int c[50001];//最后牌局 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){//局次 
		for(int j = i;j <= n;j++){//出牌编号 
			for(int z = i;z < j;z++){//排重 
				if(c[z] == a[j]){
					for(int x = z;x < j;x++){//清空 
						c[x] = 0;
					} 
					break; 
				}
			}
			c[j] = a[j];
		}
		for(int j = i;j <= n;j++){//统次 
			b[c[j]]++;
		} 
	}
	for(int i = 1;i <= m;i++){
		if(b[i] != 0)
			cout << b[i] << " "; 
	}
}

