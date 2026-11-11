#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3){
		cout<<'1';
		string p1,p2;
		p1 = s2[0]+s2[1];
		p2 = s4[0]+s4[1];
		if(p1 == p2){
			cout<<'1';
			char c1,c2;
			c1 = s2[2];
			c2 = s4[2];
			int kk1,kk2;
			kk1 = c1+1;
			kk2 = c2+1;
			if(kk1/3 == kk2/3){
				cout<<'1';
				int b = max(kk1,kk2);
				int b1 = kk1+kk2-b;
				int y = b%3;
				int y1 = b1%3;
				if(kk1/3 == 23){
					cout<<'1';return 0;
				}else if(y -y1 == 1||y-y1 == -1){
					cout<<'1';return 0;
				}else{
					cout<<'0';return 0;
				}
			}else{
				cout<<"00";return 0;
			}
			
		}else {
			cout<<"000";return 0;
		}
	}else{
		cout<<"0000";return 0;
	}return 0;

}
