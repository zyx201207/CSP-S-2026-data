#include<iostream>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out.txt","w",stdout);
	int n,m=0,a[90];
	cin>>n;
	for(int i=0;i>=n;i++){
	cin>>a[i];
	m++; 
	}
	cout<<m/2;
	return 0;
}
