#include <bits/stdc++.h>
using namespace std;
int mi(){
	int n,d,land[10005],u = 0;
	cin>>n>>d;
	for(int i = 1;i<=d;i++){
		cin>>land[i];
	}
	for(int j = 1;j<=d;j++){
		for(int i = d;i>=1;i++){
			for(int h = d;h>=1;h++){
				if(land[1]+h+i==land[n]&&h!=i){
					u++;
				}
			}	
		}
	}
	cout<<u<<endl;
}
int main(){
	int c,t;
	cin>>c>>t;
	for(int i = 1;i<=t;i++){
		mi();
	}
	return 0;
}
