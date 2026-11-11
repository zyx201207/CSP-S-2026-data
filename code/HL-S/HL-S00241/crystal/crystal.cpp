#include <bits/stdc++.h>
using namespace std;
long long n,m,t,sum = 1,e = 0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	long long sj[n+5];
	for(int j = 0;j < n;j++){
		cin >> sj[j];
	}
	 for(int s = 0;s < m;s++){
	 	
		for(int q = 0;q < n;q++){
		    for(int x = 0;x < n;x++){
				if(q == x){
					continue;
				}
				if(sj[q] < sj[x]){
					t = 1;
				}
				else{
    				t = 0;
					q++;
				}
			}
			if(t == 1){
				sj[q]++;
			}
		}
	 }

	
	for(int q = 0;q < n;q++){
		if(sj[q]==sj[q+1]){
			sum+=1;
		}
	}
	cout << sum+1;
	
	return 0;
}
