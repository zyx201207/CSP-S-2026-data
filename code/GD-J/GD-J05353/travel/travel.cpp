#include<bits/stdc++.h>
using namespace std;
long long c1,c2,t=4;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(0);cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		t--;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<"1";
			t--;
			if(s1[2]>='D'&&s2[2]>='D'){
				cout<<"11";
				t=0;
			}else if(s1[2]<='C'&&s2[2]<='C'){
				cout<<"1";
				t--;
				for(char c='A';c<='C';c++)
					if(s1[2]==c&&(s2[2]==c-1||s2[2]==c+1)){
						cout<<"1";
						t--;
						break;
					}
			}
		}
	}
	while(t--)cout<<"0";
	return 0;
}
