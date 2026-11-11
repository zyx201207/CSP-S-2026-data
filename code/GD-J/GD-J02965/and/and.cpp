#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,max_1=0;
	cin >> n >> m;
	int a[n];
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			max_1=max(max_1,a[i]);
		}
		cout << max_1;
		return 0;
	}
	if(m==n){
		max_1=a[1];
		for(int i=2;i<=n;i++){
			max_1=max_1|a[i];
		}
		cout << max_1;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				max_1=max(max_1,a[i]&a[j]); 
//				cout << a[i] << " " << a[j] << " " << (a[i]&a[j]) << endl;
			}
		}
	}
	cout << max_1;
	return 0;
}
