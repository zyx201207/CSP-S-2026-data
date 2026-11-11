#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string str;
	for(int i=1;i<=n;i++){
		int x;
		string z;
		cin>>x;
		cin>>z;
		for(int j=1;j<=x;j++){
			str+=z;
			
		}
		
		
	}
	
	int q=str.size(),m=0;
	for(int i=0;i<q/2;i++){
		if(str[i]!=str[q-1-i]){
			m++;
		}
	}
	cout<<m;
	
	return 0;
} 
