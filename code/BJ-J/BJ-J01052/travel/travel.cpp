#include<bits/stdc++.h>
using namespace std;

string s11,s12,s21,s22;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>s11>>s12>>s21>>s22;
	if(s11==s21){
		cout<<"1";
		if(s12[0]==s22[0]&&s12[1]==s22[1]){
			cout<<"1";
			if(s12[2]>s22[2])
				swap(s12[2],s22[2]);
			if(s12[2]>='D'||s22[2]<='C'){
				cout<<"1";
				if(s22[2]-s12[2]<=1)
					cout<<"1\n";
				else
					cout<<"0\n";
			}else
				cout<<"00\n";
		}else
			cout<<"000\n";
	}else
		cout<<"0000\n";
	return 0;
}