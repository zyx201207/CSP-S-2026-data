#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin >> n >> m;
	int a[n];
	for(int i = 0;i < n;i ++){
		cin >> a[i];
	}
	int sound; 
	for(int i = 0;i < m;i ++){
		int maxa = a[i];
		for(int j = 0;j < n;j ++){
			if(maxa < a[j]){
				maxa = a[j];
			}
			else{
				swap(a[j],a[j + 1]);
			}
		}
		n --;
		if(i == m - 1){
			sound = maxa; 
		}
	}
	cout << sound;
}
