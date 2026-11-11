#include <bits/stdc++.h>
using namespace std;
const int N = 5 * (1e5+1);
int n,m,sum = 0,s=0;
double a[N],p;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n;
	cin >> m;
	for (int i=0;i<n;i++){
		cin >> a[i];
	}
	for (int i=0;i<n;i++){
		sum+=a[i];
	}
	p = sum/n;
	for (int i=0;i<n;i++){
		if (a[i]<p){
			for (int j=a[i];j<=p-a[i]+2;j++){
				if (m>=1){
					a[i]++;
					m--;
				}else{
					break;
				}
			}
		}
	}
	for (int i=0;i<=n;i++){
		if (a[i] == a[i+1]){
			s++;
		}
	}
	cout << s; 
	return 0;
}
