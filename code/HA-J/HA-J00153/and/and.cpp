#include<bits/stdc++.h>
using namespace std;

int a[200005];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n;
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	int a_min=a[0];
	for(int i=0;i<n-1;i++){
		a_min=min(a_min,a[i]);
	}
	
	if(m == 1){
		cout << a_min;
	}
	else if(m == 2){
		int x=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				x=max(a[i],a[j]);
			}
		}
		cout << x;
	}
	else if(m == n){
		for(int i=0;i<n;i++){
			a_min = (a_min & a[i]);
		}
		cout << a_min;
	}
	return 0;
}
