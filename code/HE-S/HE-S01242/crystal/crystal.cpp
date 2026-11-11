#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r","stdin");
	freopen("crystal.out","r","stdout");
	int n,m,d;
	cin<<n,m;
	int a[n];
	for(int i=0;i<n;i++){
		cin<<a[i];
	}
	for(int i=0;m>0 && i<n;i++){
		for(int j=0;j<i;j++){
			if(a[i]<a[j]){
				a[i]++;
				m--;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			if(a[i]==a[j]){
			d++;
			}
		}
	}
	cout>>d;
	
}
