#include<iostream>
using namespace std;
int c,t,n;
long long int d,a[2000001],cnt;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	for(int j3=0;j3<t;j3++){
		cin >> n >> d;
		for(int i=0;i<n;i++){
			cin >> a[i];
		}
		for(int i=0;i<n-2;i++){
			for(int j=3;j<n-i;j++){
				if(a[j]-a[i]<=d){
					continue;
				}
				if((a[j]-a[i])%d!=0){
					cnt++;
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
