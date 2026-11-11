#include<bits/stdc++.h>
using namespace std;
int a[10000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	cin>>n;
	int m;
	cin>>m;
	int t=0;
	if(m=8){
		t++;
	}
	for(int j=0;j<n;j++){
		cin>>a[j];
		
		
	
	
	sort(a,a+n);
		a[j]++;
		if(a[j]==a[j++]){
			t++;
			m--;	
		}
		
		if(m==0){
			break;
		}
	}
	
	cout<<t;
	return 0;
} 
