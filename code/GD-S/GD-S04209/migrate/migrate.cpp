#include<bits/stdc++.h>
using namespace std;
int c,T,n,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> T;
	while(T--){
		int ans=0;
		cin >> n >> d;
		if(d>1){
			cout << max(0,n-2) << '\n';
		}else{
			cout << "0\n";
		}
		for(int i=0;i<n;i++){
			cin >> c;
		}
	}
	fclose(stdin);
	fclose(stdout);
}
