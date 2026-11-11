#include<bits/stdc++.h>
using namespace std;
long long a[]={};
int main(){
	int n,m,max;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		max=a[i];
		if(max>a[i]){
			cout << max;
		}
	}
	//freopen("and","r",stdin);
	//freopen("and","w",stdout);
	return 0;
}

