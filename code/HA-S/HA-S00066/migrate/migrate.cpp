#include <bits/stdc++.h>
using namespace std;
long long a[2000010],cnt;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d;
	cin >> c >> t;
	while(t--){
		cnt=0;
		cin >> n >> d;
		for(int i=1;i<=n;i++){
			cin >> a[i];
		}
		int k=a[2]-a[1],l=1;
		if(k>d/2||k<=d/3) {
			cout << 0 << endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				if((j-i)%2==1) cnt++;
			}
		} 	
		cout << cnt << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
