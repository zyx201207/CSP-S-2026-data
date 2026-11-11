#include<bits/stdc++.h>
using namespace std;

string a,b,c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,x;
	
	cin>n;
	for(int i=1;i<=n;i++){
		cin>>x;
		for(int j=1;j<=x;j++){
			cin>>b;
			a+=b; 
		}
	}
	int sum=0;
	for(int i=a.size()-1;i>=0;i--){
		
		
	
		if(a[i]==c[i]){
		sum++;
	}
	}
	cout<<sum;
	
	return 0;
}
