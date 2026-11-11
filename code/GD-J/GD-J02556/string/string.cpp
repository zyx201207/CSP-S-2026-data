#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    int n;
	cin >> n;
	int a[1000000000];
	string b;
	string c;
	int wt = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i] >> b[i];
	}
	for(int i = 0; i < n; i++){
		for(int j = 1; j <= a[i]; j++){
			c[wt] = b[i];
			wt++;
		}	
	}
	int r = c.size();
	int cnt = 0;
	int h = r / 2;
	for(int i = 0; i <= h; i++){
		if(c[i] != c[r - i]){
			c[i] = c[r -i];
			cnt++;
		}
		else{
			continue;
		}
	}
	cout << cnt << endl;
	return 0;
}
