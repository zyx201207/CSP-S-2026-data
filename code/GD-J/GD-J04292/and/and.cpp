#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	long long max = -1,a;
	cin >> n >> m;
	if(m == 1){
		for(int i=0;i<n;i++){
			cin >> a;
			if(max < a){
				max = a;
			}
		}
		cout << max;
	}
	if(m == n){
		cin >> max;
		for(int i=1;i<n;i++){
			cin >> a;
			max = (max & a);
		}
		cout << max;
	}
	return 0;
}
