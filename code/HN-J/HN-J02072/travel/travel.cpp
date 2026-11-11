#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,b1,b2;
	cin>>a1>>a2>>b1>>b2; 
	if(a1==b1){
		cout<<"1";
		int sit1=(a2[0]-'0')*10+(a2[1]-'0');
		int sit2=(b2[0]-'0')*10+(b2[1]-'0');
		if(sit1==sit2){
			cout<<"1";
			int s1=a2[2]-'A'+1,s2=b2[2]-'A'+1;
//			cout<<endl<<a2[2]<<" "<<b2[2];	
//			cout<<endl<<s1<<" "<<s2<<" "<<abs(s1-s2)<<endl;
			if(s1>=4&&s2>=4){
				cout<<"11";
			}else if(s1<=3&&s2<=3){
				cout<<"1";
				
				if(abs(s1-s2)==1){
					cout<<"1";
				}else{
					cout<<"0";
				}
				
			}else{
				cout<<"00";
			}
			
		}else{
			cout<<"000";
			
		}
		
	}else{
		cout<<"0000";
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
