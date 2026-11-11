#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,m=0,a,cnt;
	string b,p;
	cin>>n;
	int x[n+5];
	string y[n+5];
	for(int i=0;i<n;i++){
		cin>>x[i]>>y[i];
	}
	for(int i=0;i<n;i++){
		for(int j=1;j<=x[i];j++){
			b+=y[i];
		}
	}
	for(int i=b.size()-1;i>=0;i--){
		p+=b[i];
	}
	a=b.size();
	for(int i=0;i<a;i++){
		if(b[i]==p[i]){
			m++;
		}	
	}
	if(m==a){
		cout<<0;
		return 0;
	}
	cout<<a-m;
	return 0;
	/*for(int i=1;;i++){
		b[i]=b[b.size()-i];
		for(int i=b.size()-1;i>=0;i--){
			p+=b[i];
		}
		cnt++;
		int www=0;
		for(int z=0;z<a;z++){		
			if(b[z]==p[z]){
				www++;
			}
			c
			if(www==a){
				out<<cnt;
				return 0;
			}
		}	
	}*/
} 
