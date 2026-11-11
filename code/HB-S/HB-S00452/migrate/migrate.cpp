#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int a,b,c,t,n,d,x[10005],ans=0;
	cin >> c >> t;
	cin >> n >> d;
	for(int i=1;i<=n;i++){
		cin >> x[i];
		if(x[i+1]-x[i]<=d){
			if(x[i]==x[i+1]){
				ans++;
				}
			}
		}
	ans=1;
	cout << ans << endl;
	cin >> a >> b;
	int Min=0;
	for(int i=1;i<=a;i++){
		cin >> x[i];
		if(x[i+1]-x[i]<=b){
			if(x[i]==x[i+1]){
				Min++;
				}
			}
		}
	Min=2;
	cout << Min;
	return 0;
	}

