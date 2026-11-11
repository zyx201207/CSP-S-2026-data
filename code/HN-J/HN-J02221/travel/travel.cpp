#include<iostream>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,s1,c2,s2;
	char s01,s02;
	cin>>c1>>s1>>s01>>c2>>s2>>s02;
	//cout<<c1<<s1<<s01<<c2<<s2<<s02;
	if(c1==c2)
		cout<<"1";
	else cout<<"0";
	if(s1==s2){
		if(c1==c2){
			cout<<"1";
		}else cout<<"0";
	}else cout<<"0";
	if(s01>67&&s02>67||s02<=67&&s01<=67){
		if(c1==c2){
			if(s1==s2){
			cout<<"1";
		}
		}else cout<<"0";
		
			
	}else cout<<"0";
	if(s01-s02==1||s02-s01==1){
		if(c1==c2){
			if(s1==s2){
			if(s01>67&&s02>67||s02<=67&&s01<=67){
		cout<<"1";	
	}else cout<<"0";
		}else cout<<"0";
		}else cout<<"0"; 
		
		
	}else cout<<"0";
	return 0;
}





