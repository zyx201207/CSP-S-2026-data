#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[n],b[n];
	bool t[n];
	for(int i = 0;i <n;i++){
		cin >> a[i];
		t[i] = 1;
	}
	int mini = 1000001,mt = 0;
	for(int i = 0;i < n;i++){
		 b[i] = 0;
		for(int j = 0;j < n;j++){
			if(a[i] - a[j] >= 0){
				b[i]+= a[i] - a[j];
			}else{
				b[i]-= a[i] - a[j];
			}
			
    	}
    	if(b[i] < mini){
			mini = b[i];
			mt = i;
		}
	}
    
    int mj = 0;
	for(int i = 0;i < mt;i++){
		mini = 917813;
		for(int j = 0;j < mt;j++){
			if(a[mt] - a[j] < mini && t[j] == 1){
				mini = a[mt] - a[j];
				mj = j;
			}
		
    	}
    	while(a[mj] != a[mt]){
    		a[mj]++;
    		m--;
    		if(m == 0)break;
		}
		t[mj] = 0;
	}
	int sum = 0;
	for(int i = 0;i <n;i++){
		if(a[i] == a[mt])sum++;
	}
	cout << sum;
	return 0;
} 
