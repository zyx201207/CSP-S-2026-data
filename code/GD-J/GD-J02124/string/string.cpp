#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n,i,a,j,z=0,b=0;
	char c;
	string s;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a>>c;
		z+=a;
		for(j=0;j<a;j++){
			s+=c;
		}
	}
	if(z%2==0){
		for(i=0;i<z/2;i++){
			if(s[i]!=s[i+z/2]){
				b+=1; 
			}
		}	
	}else{
		for(i=0;i<z/2;i++){
			if(s[i]!=s[i+z/2+1]){
				b+=1; 
			}
		}
	}
	cout<<b;
	return 0;
}
