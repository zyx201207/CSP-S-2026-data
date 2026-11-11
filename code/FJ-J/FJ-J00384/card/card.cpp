#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card1.in","r",stdin);
	freopen("card1.ans","w",stdout);
	int m,n,cnt,h;
	cin >> n >> m;
	int a[10086],b[114514];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int x = 0,y = 0,z = 0;
	for(int g = n; g > 0; g--){
		for(int i = 0; i < n; i++){
			a[i] == b[i];
			for(int j = 1; j < n; j++){
				if(a[i] == a[j]){
					for(int k = i; k < j; k++){						
						h = k;
						a[k] == a[j++];
					}
				}
				if(a[i] == 1){
					x++;
				}else if(a[i] == 2){
					y++;
				}else{
					z++;
				}
			}
			a[i] = b[h];
		}
	}
	cout << x << " " << y << " " << z;
	return 0;
}
