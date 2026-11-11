#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","r",stdout);
	int R,X;
	string r,x;
	cin>>R>>r>>X>>x;
	if(R==X) cout<<1;
	else{
	cout<<"0000";
	return 0;
	}
	if(r[0]==x[0] && r[1]==x[1]){
		cout<<1;
	}
	else{
	cout<<"000";
	return 0;
	}
	if(abs(r[2]-x[2])>2){      
	 cout<<"00";
	 return 0;
	}
	else
	{
		cout<<1;
	}
	if(abs(r[2]-x[2])==1){
		cout<<1;
	}
	else{
		cout<<0;
	}

	return 0;
} 
