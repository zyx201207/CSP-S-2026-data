#include<bits/stdc++.h>
using namespace std;
int c[100004];
int f(int n,int m){
	int b[n];
	long long s = pow(2,27)-1;
	for(int i = 1;i<=m;i++){
		b[i] = 1;
	}
	for(int i = m+1;i<=n;i++){
		b[i] = 0;
	}
	long long big = 0;
	for(int j = 1;j<=n;j++){
		int i = 1;
		while(b[n]!=1){
			if(b[i]){
				s = s and c[i];
				i++;
			}
			if(i>m){
				break;
			}
		}
		big = max(big,s);
		s = pow(2,27)-1;
		b[1]++;
		for(int i = 1;i<=n;i++){
			
			if(b[i]>1){
				b[i] = 0;
				b[i+1]++;
			}
			int sum = 0;
			for(int j = 1;j<=n;j++){
				if(b[j] = 1){
					sum++;
				}
			}
			if(sum!=m){
				b[1]++; 
			}
		}
	}
	return big;
}
int main(){
	int n,m;
	int s = 0;
	cin>>n>>m;
	for(int i = 0;i<n;i++){
		cin>>c[i];
	}
	for(int i  = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			if(i!=j){
				s = max(s,c[i] & c[j]);	
			}
		}
	}
	cout<<s;
}
