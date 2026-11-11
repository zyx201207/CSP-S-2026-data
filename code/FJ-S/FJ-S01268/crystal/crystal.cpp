#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,max=0;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++) {
		cin>>a[i];
	}
	int w=1;
	while(m!=0) {
		if(a[w-1]!=a[w]){
			for(int i=0;i<w;i++){
				a[i]++;
			}
			m=m-w;
		}else{
			w++;
		}
	}
	for(int i=0;i<n;i++) {
		if(a[i]==a[0]){
			max++;
		}
	}
	cout<<max;
	return 0;
}
//1 2 4 8 9
// 1 2 4 1
//
//-3 -1 2 2 7
//  2  3 0 5
