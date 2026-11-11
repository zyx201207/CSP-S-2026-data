#include<bits/stdc++.h>
using namespace std;
int a[500005],tmp[500005],cnt[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	bool is = true;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(a[i] < a[i - 1]) is = false; 
	}
	if(is == true){
		for(int i = 1;i <= n;i++){
			for(int j = a[i];j <= m;j++){
				cnt[j]++;
			}
		}
	}else{
		for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
			for(int k = i;k < j;k++){
				if(tmp[k] == a[j]){
					for(int x = k;x < j;x++) tmp[x] = -1;
				}
			}
			tmp[j] = a[j];
		}
		for(int j = i;j <= n;j++){
			if(tmp[j] != -1) cnt[tmp[j]]++;
		}
	}
	}
	for(int i = 1;i <= m;i++){
		cout << cnt[i] << " ";
	}
	return 0;
}

