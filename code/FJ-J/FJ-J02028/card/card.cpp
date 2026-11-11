#include <bits/stdc++.h> 
using namespace std;
int n,m;
int a[5000001];
int main(){
cin >>n>>m;
for(int i=1;i<=n;i++){
	cin >>a[i];
} 
int table[100001];
for(int i=1;i<=n;i++){
	table[i]=a[i]
	if(a[i] == a[i+1]){
		table[i]=0;
	}
}
for(int i= 1;i<=n;i++){
	if(table[i]!=0){
		cout << table[i]
	}
}
	return 0;

}
