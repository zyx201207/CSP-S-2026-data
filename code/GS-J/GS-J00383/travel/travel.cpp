#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a="0",b="0";
	string a1="0",b1="0";
	cin>>a>>a1>>b>>b1;
	if(a!=b){
		cout<<"0";
		cout<<"0";
		cout<<"0";
		cout<<"0";
		return 0;
	}
	if(a==b){
		cout<<"1";
		if(a1[0]==b1[0]&&a1[1]==b1[1]){
			cout<<"1";
		  if(a1[2]+0<68&&b1[2]+0<68)
		  {
		  	cout<<"1";
		  	if(a1[2]-b1[2]==-1||a1[2]-b1[2]==1){
		  		cout<<"1";
			  }else{
			  	cout<<"0";
			  }
		  }else if(a1[2]+0>67+0&&b1[2]+0>67){
		  	cout<<"1";
		  	if(a1[2]-b1[2]==-1||a1[2]-b1[2]==1){
		  		cout<<"1";
			  }else{
			  	cout<<"0";
			  }
		  }else{
		  	cout<<"0";
		  	cout<<"0";
		  }
		}else{
			cout<<"0";
			cout<<"0";
			cout<<"0";
		}
	}
	return 0;
}
