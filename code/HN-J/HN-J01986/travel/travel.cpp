#include<bits/stdc++.h>
using namespace std;
int ans[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s11,s12,s21,s22;
	cin>>s11>>s12>>s21>>s22;
	if(s11!=s21){
		cout<<"0000";
		return 0;
	}
	else{
		string s13="";
		s13+=s12[0];
		s13+=s12[1];
		string s23="";
		s23+=s22[0];
		s23+=s22[1];
		if(s13!=s23){
			cout<<"1000";
			return 0;
		}
		else{
			int ans1,ans2;
			if(s12[2]=='A'||s22[2]=='A'){
				ans1++;
				ans[1]++;
			}
			if(s12[2]=='B'||s22[2]=='B'){
				ans1++;
				ans[2]++;
			}
			if(s12[2]=='C'||s22[2]=='C'){
				ans1++;
				ans[3]++;
			}
			if(s12[2]=='D'||s22[2]=='D'){
				ans2++;
				ans[4]++;
			}
			if(s12[2]=='E'||s22[2]=='E'){
				ans2++;
				ans[5]++;
			}
			if(ans1!=2&&ans2!=2){
				cout<<"1100";
				return 0;
			}
			else{
				bool kk=0;
				if(ans[1]==1&&ans[2]==1)
					kk=1;
				if(ans[2]==1&&ans[3]==1)
					kk=1;
				if(ans[4]==1&&ans[5]==1)
					kk=1;
				if(kk==0){
					cout<<"1110";
					return 0;
				}
				else{
					cout<<"1111";
					return 0;
				}
			}
		}
	}
	return 0;
}
