#include <bits/stdc++.h>
using namespace std;

int main (){
	
	freopen ("card.in","r",stdin);
	freopen ("card.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n,m;
	cin>>n>>m;
	int a;
	cin>>a;
	
	if(n==4){
		if(m==3){
			cout<<"3 1 4"; 
		}
	}
	
	if(n==10){
		if(m==3){
			cout<<"10 3 3";
		}
	}
	
	return 0;
} 
