#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<'1';
		if(s1.substr(0,2)==s2.substr(0,2)){
			cout<<'1';
			char a=s1[s1.size()-1],b=s2[s2.size()-1];
			if((a>='A' && a<='C' && b>='A' && b<='C') || (a>='D' && a<='F' && b>='D' && b<='F')){
				cout<<'1';
				if(abs(a-b)<=1 || (a=='D' && b=='F') || (a=='F' && b=='D'))
					cout<<'1';
				else cout<<'0';
				cout<<'\n';	
			}
			else cout<<"00\n";
		}
		else cout<<"000\n";
	}
	else cout<<"0000\n";
	return 0;
}
