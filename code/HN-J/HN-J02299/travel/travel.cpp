#include<bits/stdc++.h>
using namespace std;
freopen ("string.in","r",stdin)
freopen ("string.out","w",stdout)

	int main(){
		char s;
	string c,c1,c2,c3;
		int x,y,z=0,a=1,u;
		cin>>x;
	
		for(int m=1;m<=x;m++)
		{
			
			cin>>y>>s;
		while(a<=y)
		{
		c[z]=s;
		z=z+a;
		a++;	
		}a=0;
	
	}
	for(int n=1;n<z/2;n++){
		c1[n]=c[n];
		for(int e=z/2;e<z;e++){
		c2[n]=c[e];
	}
	for(int j=1;j<=n;j++){
		c3[j]=c2[j];
		if(c3[j]!=c1[j]){
			u=u+1;
		}
	}
	
	}
	cout<<u;
return 0;
}
