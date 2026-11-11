#include<bits/stdc++.h>
using namespace std;
int sum,c,t,n,d,x[10000005],y[10000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t<0){
		cin >> n >> d;
		for(int i=1;i<=n;i++){
			cin >> x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(abs(x[i]-x[j])<=d){
					y[i]==abs(x[i]-x[j]);
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				sum++;
			}
		}
		cout << sum << endl;
		t--;
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
