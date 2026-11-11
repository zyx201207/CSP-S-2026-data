#include<bits/stdc++.h>

using namespace std;
int n,m;
long long a[200005],da=0,da2=0,j[200005],o[200005],jz=0,oz=0;
long long zdjo=1e9;
int main(){
	ifstream("D:\GD-J02607\and\and.in");
	ofstream("D:\GD-J02607\and\and.out");
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]%2==0){
			o[oz]=a[i];
			oz++;
		}
		else{
			j[jz]=a[i];
			jz++;
		}
	}
	sort(o,o+oz);
	sort(j,j+jz);
	int cnt=o[oz-1];
	int ant=j[jz-1];
	for(int i=oz-2;i>=oz-m;i--){
		cnt=cnt&o[i];
	}
	for(int i=jz-2;i>=jz-m;i--){
		ant=ant&j[i];
	}
	cout<<max(cnt,ant)<<endl;
}
