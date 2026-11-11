#include<bits/stdc++.h>
using namespace std;
int a1[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,MAX = 0;
	cin >> n >>m;
	for(int j = 1;j<=n;j++){
		cin >> a1[j];
	}
	if(m == 2){
		for(int i = 1;i<=n;i++){
			for(int j = i+1;j<=n;j++){
				if(a1[i]&a1[j]>=MAX){
					MAX = a1[i] & a1[j];
				}
			}
		}
		cout << MAX;
	}
	if(m == 1){
		for(int i = 1;i<=n;i++){
			if(a1[i]>=MAX){
				MAX = a1[i];
			}
		}
		cout << MAX;
	}
}
