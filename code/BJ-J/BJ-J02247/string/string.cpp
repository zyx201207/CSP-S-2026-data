#include<bits/stdc++.h>
using namespace std;

char a[10000010],b[10000010];

int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n,xia = 1;
	
	cin >> n;
	
	for(int i = 1;i <= n;i++){
		int ai;
		char ci;
		cin >> ai >> ci;
		ai += xia;
		for(int i = xia+1;i <= ai;i++){
			a[xia] = ci;
			xia++;
		}
	}
	
//	for(int i = 1;i <= xia-1;i++)cout << a[i];
//	cout << endl;
	
	for(int i = 1;i <= xia-1;i++){
		b[i] = a[xia-i];
//		cout << b[i];
	}
	
	int dif = 0;
	
	for(int i = 1;i <= xia/2;i++){
		if(a[i] != b[i]){
			dif++;
//			cout << i << " ";
		}
	} 
	
	cout << dif;
	
	return 0;
	
}
