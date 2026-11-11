#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel","r",stdin);
	freopen("travel","w",stdout);
	int sum1,sum2,sum3,sum4;
	int c1,c2;
	srting s1,s2;
	cin>>c1>>s1>>c2>>s2;
	

	if(c1!=c2){
		sum1=0;sum2=0;sum3=0;sum4=0;
	}
	if(c1==c2)
		sum1=1;

	
	
	cout<<sum1<<sum2<<sum3<<sum4;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
