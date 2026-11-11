#include<bits/stdc++.h>
using namespace std;
int s[500100];
bool flag[500100];
int tong[500100];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> s[i];
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			flag[j] = false;
		}
		for(int j = i;j <= n;j++){
			if(flag[s[j]] == false){
				flag[s[j]] = true;
			}else{
				for(int k = i;k <= n;k++){
					if(s[k] == s[j]){
						for(int kk = k+1;kk <= j;kk++){
							if(s[kk] != s[j]) flag[s[kk]] = false;			
						}
						break;
					}
				}
			}
		}
		for(int i = 1;i <= m;i++){
			if(flag[i] == true){
				tong[i]++;
			}
		}
	}
	for(int i = 1;i <= m;i++){
		cout << tong[i] << " ";
	}
	return 0;
}
