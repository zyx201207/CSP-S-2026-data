#include<bits/stdc++.h>
using namespace std;
int n,m,a[8],b[8];
string r1,x1,r2,x2;
int main(){
	freopen("travelin","r",stdin);
	freopen("travelout","w",stdout);
	cin>>r1>>x1>>r2>>x2;
	if(r1==r2){
		cout<<1;
		for(int i=0;i<2;i++){
			n=n*10+(x1[i]-'0');
			m=m*10+(x2[i]-'0');
		}
		if(n==m){
			cout<<1;
			if(x1[2]<='C'){
				a[0]=1;
			}
			else{
				a[0]=0;
			}
			if(x2[2]<='C'){
				b[0]=1;
			}
			else{
				b[0]=0;
			}
			if(a[0]==b[0]){
				cout<<1;
				if(x1[2]+1==x2[2]||x1[2]-1==x2[2]||x2[2]+1==x1[2]||x2[2]-1==x1[2]){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
				cout<<0<<0;
			}
		}
		else{
			cout<<0<<0<<0;
		}
	} 
	else{
		cout<<0<<0<<0<<0;
	}
	
	
	return 0; 
}
