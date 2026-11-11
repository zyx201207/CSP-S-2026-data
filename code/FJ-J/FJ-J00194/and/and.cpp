//#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a[(int)1e6+10];

bool cmp(int x,int y){
	return x > y;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,shu=0,b;
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	for(int i=0;i<n;i++){
	     b = a[i];
		 for(int j=i+1;j<n;j++){
		 
		 	
			if ((b &= a[j])>=shu){
				shu = b;
			}
	}
		
	}
	
	cout << shu;
	
	return 0;
}
