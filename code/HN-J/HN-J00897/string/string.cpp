#include<bits/stdc++.h>
using namespace std;

int n;
string S,c;
long long a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	int m,num=0,o=0,P=0;
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		cin>>c;
		num+=a;
		for(int j=0;j<a;j++){
			S+=c;
		}
	}
	if(num%2==1){
		m=1;
	}
	else {
		m=0;
	}
	if(m=1){
		num-1;
		int u=1,U=num/2;
		for(int i=num/2;i<=num;i++){
			if(S[U+u]==S[U-u]){
			 	u++;
				}
			else {
			P++;
			u++;
			}
		}
	}
	if(m=0){
		int U=num/2-1,x=1,z=2,q=0;
		for(int i=num/2;i<=num;i++){
			if(q==0){
			    if(S[U]==S[U+1]){
			    	q++;
				}
				else{
				    q++;
				    P++;
				}
			}
			else{
				if(S[U-x]==S[U+z]){
					x++;
					z++;
				}
				else{
					x++;
					z++;
					P++;
				}
			}
		}
	}
	cout<<P;
	return 0;
}
