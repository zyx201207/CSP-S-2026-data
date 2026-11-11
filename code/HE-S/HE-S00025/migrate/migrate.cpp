#include <iostream>
using namespace std;
int c,t,n,d,x[1000005],f[1000005],cnt,last;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		/*for(int i = 1;i <= n;i++){
			cin >> x[i];
		}
		for(int i = 1;i <= n;i++){
			x[i] = x[i]-x[i-1];
		}
		f[1] = 0;
		if(d/x[2]){
			f[2] = 1;
		}
		for(int i = 3;i <= n;i++){
			if(d/x[i] == 0){
				break;
			}
			
		}
		*/
		cnt = 0;
		for(int i = 1;i <= n;i++){
			cin >> x[i];
		}
		last=x[2]-x[1];
		for(int i = 1;i < n;i++){
			if(x[i+1]-x[i] == last){
				cnt++;
			}
		}
		if(cnt == n-1){
			if(d/last == 2){
				cout << n-3 << "\n";
			}
			else{
				cout << 0 << "\n";
			}
		}
		else{
			if(d  == 2){
				cout << 1 << "\n";
			}
		}
	}
	
	return 0;
}
