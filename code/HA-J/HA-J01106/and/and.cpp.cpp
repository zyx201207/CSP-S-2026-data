#include <bits/stdc++.h>
using namespace std;

int n,m,a[100005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	int yyy=0;
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++){
		if(a[i] < a[i+1]){
			yyy++;
			if(yyy == m){
				cout << a[yyy];
				break;
			}
		}
	}
	return 0;
}
