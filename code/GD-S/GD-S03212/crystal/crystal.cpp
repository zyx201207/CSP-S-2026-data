#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,a=1;
	int n1[500005];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>n1[i];
	}
	while(n1[0]!=n1[2]){
		m--;
		n1[0]++;
		if(m==0){
			break;
		}
	}
	while(n1[1]!=n1[2]){
		m--;
		n1[1]++;
		if(m==0){
			break;
		}
	}
	for(int i=0;i<n;i++){
		if(n1[i]==n1[i+1]){
			a++;
		}
	}
	cout<<a;
	return 0;
} 
