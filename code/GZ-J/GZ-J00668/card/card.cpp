//GZ-J00668 遵义市新蒲新区滨湖中学 杨一凡
#include<bits/stdc++.h>
using namespace std;
int n , m;
int s[500001] , t[500001] , e[300001];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> s[i];
	for(int i = 1;i <= n;i++){
		int c = n - i + 1;
		int j = i;
		for(int f = 1;f <= c;f++) t[f] = 0;
		while(c >= 0){
			t[j] = s[j];
			c--;
			j++;
			for(int x = 1;x < j;x++){
				if(s[x] == t[j]){
					j = x;
					for(int y = j + 1;y <= c - j;y++) t[y] = 0;
				}
			}
		}for(int z = 1;t[z] != 0;z++){
			for(int g = 1;g <= m;g++){
				if(t[z] == g) e[g]++;
			}
		}
	}for(int i = 1;i <= m;i++) cout << e[i] << " ";
    fclose(stdin);
    fclose(stdout);
	return 0;
}

