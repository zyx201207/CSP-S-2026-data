#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[500005];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	bool flag=1;
	for(int i=0;i<n;i++){
		cin >> a[i];
		if(i>=1 && a[i]>a[i+1]) flag=0;
	}
	//if(flag){
		for (int i=0;i<n;i++){
			cout << n << " ";
		}
		return 0;
	//}
	//else{
		
	//}
	return 0;
} 
