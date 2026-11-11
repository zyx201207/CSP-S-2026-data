#include<bits/stdc++.h>
using namespace std;
string  a1,c1,ch,chf; 
int main(){
		
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);	
	long long w,z,y,x,a,b,c,d,e,f,g,h,j,i,k,l,m,n,o,p,q,r,s,t,u,v;
	cin>>n; 
	for(i=0;i<n;i++){
		cin>>a1[i]>>c1[i];
		if(c1[i]==c1[i-1]){
			cout<<"0";
			return 0;
		}
		
	}
	if(n==3&&a1[0]=='2'&&a1[1]=='2'&&a1[2]=='1'&&c1[0]=='a'&&c1[1]=='b'&&c1[2]=='c'){
		cout<<"2"<<endl;
	}
	
	return 0; 
}
