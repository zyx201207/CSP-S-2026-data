#include<bits/stdc++.h>
using namespace std;
int main(){
	long long int n=0,i,j,m,k=1,l,s=0,a;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>l;
    char b;
    string c;
	for(i=1;i<=l;i++){
		cin>>a>>b;
		n+=a;
		for(j=k;j<a+k;j++){
		c[j]=b;
		}
		k+=j;
	}
    if(n%2!=0){
	m=(n+1)/2;
	for(i=1;i<m;i++){
		if(c[i]!=c[n-i+1]){
		s++;
		}
		
	}
	}
	else
	{
		m=n/2;
		for(i=1;i<=m;i++){
		if(c[i]!=c[n-i+1])
		s++;
	}
	}
    cout<<s;
    
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
