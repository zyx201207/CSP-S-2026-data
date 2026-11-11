#include<iostream> 
#include<string>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){  //车厢号 
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){ //排数 
			cout<<1;
			int a=s1[2];
			int b=s2[2];
			bool n=(a<=67&&b<=67)||(a>67&&b>67); 
			if(n){ //过道 
				cout<<1;
				if(a>67&&b>67){
					cout<<1;
				}
				else{
					if(a-b==1||b-a==1){
						cout<<1;
					}
					else{
						cout<<0;
					} 
				
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
