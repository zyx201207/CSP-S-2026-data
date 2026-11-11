#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500050];
long long dengcha[500050],deng[500050];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool b = true;
	long long qw = 1;
	for(long long i = 1;i <= n;i++){
		cin>>a[i];
		if(qw != a[i]){
			b = false;
		}
		else{
			qw++;
		}
	}
	long long qe = a[n] - a[n - 1];//差值 
	bool c = true;
	for(long long i = n - 2;i >= 1;i--){
		if(qe != a[i + 1] - a[i]){
			c = false;
		}
	} 
	//性质A 
	if(b){
		for(long long i = 1;i <= n;i++){
			deng[i] = a[n] - a[i];
		}
		int num = 0;
		for(long long i = n;i >= 1;i--){
			m -= deng[i];
			if(m <= 0){
				break;
			}
			num++;
		}
		cout<<num;
	}
	//性质B
	else if(c){
		for(long long i = 1;i <= n;i++){
			dengcha[i] = a[n] - a[i];
		}
		int num = 0;
		for(long long i = n;i >= 1;i--){
			m -= dengcha[i];
			if(m <= 0){
				break;
			}
			num++;
		}
		cout<<num;
	}
	return 0;
}
