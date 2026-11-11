#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m;
	cin >> n >> m;
	
	int arr[n + 1];
	for(int i = 1;i <= n;i++){
		cin >> arr[i];
	}
	
	int count[n * m];
	int place = 0;
	for(int i = 1;i <= m;i++){
		int t[n] = {0};
		int pos = 0;
		int tlen = 0;
		for(int j = i;j <= n;j++){
			for(int k = pos;k <= pos + tlen;k++){
				if(t[k] == arr[i]){
					pos = k + 1;
				}
			}
			t[tlen] = arr[i];
			tlen++;
		}
		
		for(int k = pos;k <= pos + tlen;k++){
			count[place] = t[k];
			place++;
		}
	}
	
	for(int i = 1;i <= m;i++){
		int ans = 0;
		for(int j = 0;j < place;j++){
			if(count[j] == i){
				ans++;
			}
		}
		cout << ans << " ";
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
