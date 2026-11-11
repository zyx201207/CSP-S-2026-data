#include<bits/stdc++.h>
using namespace std;
int main(){ 
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a,s,z=0,x=0;
	char d;
	string q;
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>s>>d;
		for(int j=0;j<s;j++){
			q+=d;
			z++;
		}
	}
		for(int i=0;i<z/2;i++){
			if(q[z-i-1]!=q[i]){
				q[z-i-1]=q[i];
				x++;	
			}
		}	
	cout<<x;	
	return 0;
}
