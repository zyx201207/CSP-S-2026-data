#include<bits/stdc++.h>
using namespace std;
long long a[2000001],n,c,t,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t){
		t--;
		cin >> n >> d;
		for(int i=0;i<n;i++){
			cin >> a[i];
		}
	}
	for(int i=1;i<n;i++){
		cout << i << endl;
		if(i>4) break;
	} 
	return 0;
}
