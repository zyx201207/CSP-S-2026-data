#include<bits/stdc++.h>
using namespace std;
long long a[1000000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,max=0;
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	if(m=1){
		for(int i=0;i<n;i++){
			if(max<a[i]) {
				max=a[i];
			}
		}
		cout << max;
		return 0;
	}else if(m=2){
		for(int i=0;i<n;i++){
			for(int j=i;j<n;j++){
				if(i==j) continue;
				if(max<(a[i]&a[j])){
					max=a[i]&a[j];
				}
			}
		}
		cout << max;
		return 0;
	}
	
	return 0;
}