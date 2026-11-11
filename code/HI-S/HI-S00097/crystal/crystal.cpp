#include <bits/stdc++.h>
using namespace std;
int n,m,a[1000000],minx[100000],sum = 0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	int ans,minxx = 10000000;
	for (int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if ((a[j] <= 0) && (a[i] >= 0)){
				minx[i] += abs(a[j]) + a[i];
			}else if ((a[j] >= 0) && (a[i] <= 0)){
				minx[i] += a[j] + abs(a[i]);
			}else{
				minx[i] += abs(a[i] - a[j]);
			}
		}
		if (minx[i] < minxx){
			minxx = minx[i];
			ans = a[i];
		}
	}
	int num = 1;
	int sp;
	while(true){
		if (m <= 0){
			break;
		}
		if (a[num] < 0){
			sp = abs(a[num]) + ans;
		}else{
		    sp = ans - a[num];
	    }
		if(m >= sp){
			a[num] += sp; 
		    m -= sp;
		    num++;
	    }else{
	    	break;
		}
	}
	for (int i = 1;i <= n;i++){
		if (a[i] == ans){
			sum++;
		}
	}
	cout << sum << endl;
	return 0;
}
