#include<iostream>
#include<string>
using namespace std;
string ca,sa,cb,sb;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ca>>sa>>cb>>sb;
	if(ca == cb){
		if(sa[0]==sb[0] && sa[1]==sb[1]){
			if('A'<=sa[2] && 'C'>=sa[2] && 'A'<=sb[2] && 'C'>=sb[2]){
				if(sa[2]=='A' && sb[2]=='B')cout<<"1111";
				else if(sb[2]=='A' && sa[2]=='B')cout<<"1111";
				else if(sa[2]=='C' && sb[2]=='B')cout<<"1111";
				else if(sb[2]=='C' && sa[2]=='B')cout<<"1111";
				else cout<<"1110";
			}
			else if('D'==sa[2] && 'F'==sb[2]){
				cout<<"1111";
			}
			else if('D'==sb[2] && 'F'==sa[2]){
				cout<<"1111";
			}
			else cout<<"1100";
		}
		else cout<<"1000";
	}
	else cout<<"0000";
	return 0;
}
