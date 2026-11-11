# include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	int x = 0;
	int y = 0;
	int z = 0;
	cin >> n >> m;
	for(i = 1,i <= n,i++){
		cin >>a[i];
	}
	d = [10001];
	for(j = 0,j <= n,j++){
		d += a[j];
		if(a[j] == a[j-1]){
			remove(a[j]);
		}
	}
	if(a[j] == 1){
		x += 1;
	}
	else if(a[j] == 2){
		y += 1;
	}
	else{
		z += 1;
	}
	cout << x,y,z;
	return 0;
}
