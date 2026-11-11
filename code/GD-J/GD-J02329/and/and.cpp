#include<bits/stdc++.h>
using namespace std;
int n,m;
int s[1000005];
int mx;
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> s[i];
	} 
	for(int i=0;i<n-1;i++){
		max(s[i],mx);}
	
	cout<<mx;
	return 0;
} 
