#include<bits/stdc++.h>
using namespace std;
int c,t,a,b,cnt=0,sum=0;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);

	cin>>c>>t;
	int v=t*5;
	while(cin>>a>>b && v--){
		cnt+=a;
		sum+=b;
	}
	int g=t/2; 
	while(g--){
		if(cnt%2==0){
		cout<<"2"<<endl;
	}
	else
	{
	cout<<"1"<<endl;	
	}
		if(sum%2==0){
		cout<<"1"<<endl;
	}
	else
	{
		cout<<"2"<<endl;
	}
	}return 0;
	}
	
		
