#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("and,in","r",stdin);
	freopen("and,out","w",stdout);
	int n,m,max=0;
	cin >> n >> m;
	int a[n];
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	max = a[0] and a[1];
	for(int i=0;i<n;i++){
		if(a[i] and a[1+1]>=max){
			max = a[i] and a[1+1];
		}
	}
	cout << max;
	
	return 0;
} 
