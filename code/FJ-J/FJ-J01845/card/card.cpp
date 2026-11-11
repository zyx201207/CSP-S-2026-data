#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	long long n,m,max = 0,end = 0,yd = 0;
	cin >> n >> m;
	int a[n],cd[n];
	for(int i = 0;i < n;i++){
		cin >> a[i];
		if(a[i] > max) max = a[i];
	}
	int b[max];
	for(int i = 0;i < max;i++){
		b[i] = 0;
	}
	for(int l = 0;l < n;l++){
		end = 0;
		for(int i = l;i < n;i++){
			yd = 0;
			if(end != 0){
				for(int j = 0;j < end;j++){
					if(cd[j] == a[i]){
						yd = 1;
						end = j;
					}
					if(yd == 1){
						cd[j] = 0;
					}
				}
			}
			cd[end] = a[i];
			end++;
		}
		for(int o = 0;o < end;o++){
			b[cd[o]]++;
			cd[o] = 0;
		}
	}
	for(int i = 1;i <= m;i++){
		cout << b[i] << " ";
	}
	return 0;
}
