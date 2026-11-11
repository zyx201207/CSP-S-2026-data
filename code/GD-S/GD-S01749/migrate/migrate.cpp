#include <bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2000001],vid[2000001],num;
int sum(int u,int v){
	if(u == v)return 1;
	int len = u+1,mid = 0;
	while(abs(x[len]-x[u]) <= d && len <= v){
		if(vid[len] != 1){
			vid[len] = 1;
			mid += sum(len,v);
		}
		len++;
	}
	return mid;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	for(int i = 0; i < t; i++){
		cin >> n >> d;
		num = 0;
		for(int j = 0; j < n; j++){
			cin >> x[j];
		}
		for(int v = 1; v < n; v++){
			if(sum(0,v) == 2)num++;
			for(int j = 0; j < n; j++){
				vid[j] = 0;
			}
		}
		cout << num << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
