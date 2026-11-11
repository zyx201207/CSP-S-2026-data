#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	int n,m,a[200001],amax = -10000,amax1;
	cin>>n>>m;
	for(int i = 0; i < n; i++){
		cin>>a[i];
	}
	if(n == m){
		for(int i = 0; i < n; i++){
			amax = a[i-1] & a[i];
			a[i] = amax;
		}
		cout<<amax;
		return 0;
	}
	else if(m == 2){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(i == j) continue;
				else{
					if(a[i] & a[j] > amax) amax = a[i] & a[j];
				}
			}
		}
		cout<<amax;
		return 0;
	}
	else if(m == 1){
		for(int i = 0; i < n; i++){
			if(a[i] > amax) amax = a[i];
		}
		cout<<amax;
		return 0;
	}
}
