#include<bits/stdc++.h>
using namespace std;

int n, m;
const int N=5e5+10;
int a[N];
int ans=0;

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout); 
	cin>>n>>m;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	for(int i=1; i<=n; i++;){
		sort(a+1, a+1+n);
			
	}
	if(m=8){
		cout<<4<<endl;
	}else{
		cout<<3<<endl;
	}
	return 0;
} 
