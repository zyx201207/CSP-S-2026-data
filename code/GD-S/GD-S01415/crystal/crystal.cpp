#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,a[1000],s[100],q=0,p=0,b=0;
	cin>>n>>m;
	for(int i=0;i<+n;i++){
	
		cin >> a[i];
		if(a[i]==a[i+1]){
			s[i]++;
		}
		if(s[i] > s[i+1]){
			q = a[i];
		}
		if(a[i]-q+a[i+1]-q<=m){
			b++;
		}
	}
	cout << b;
	return 0;
}
