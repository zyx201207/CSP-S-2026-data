#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>a[i];
	}
	int A=a[2];
	int B=a[3];
	int C=A&B;
	cout<<C;
	return 0;
}
