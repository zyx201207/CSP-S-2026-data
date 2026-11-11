#include <bits/stdc++.h>

using namespace std;

const int N = 200000 + 100;

long long MOD = 1073741824;
long long n,m;
long long s = 0;
bool ss = 0;
long long a[N] = {0};
long long c[N] = {0};
long long daan = 0;
bool b[N] = {0};
bool f = 0;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		
		c[i] = a[i];
	}
	
	while(MOD > 0){
		s = 0;
		ss = 0;
		
		for(int i = 1;i <= n;i++){
			if(b[i] == 0 && a[i] >= MOD){
				s++;
			}
		}
		
		if(s >= m){
			ss = 1;
			daan = daan + MOD;
		}
		
		for(int i = 1;i <= n;i++){
			if(a[i] < MOD && ss == 1){
				b[i] = ss;
			}else{
				a[i] = a[i] % MOD;
			}
		}
		
		MOD = MOD / 2;
    }
	
	cout<<daan<<endl;
    
	return 0;
}
