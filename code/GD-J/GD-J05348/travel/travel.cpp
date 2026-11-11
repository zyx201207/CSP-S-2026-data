#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string c1,s1,c2,s2;
	int sit1=0,sit2=0,l1,l2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<'1';
		sit1=int(s1[0]-'0')*10+int(s1[1]-'0');
		sit2=int(s2[0]-'0')*10+int(s2[1]-'0');
		if(sit1==sit2){
			cout<<'1';
			l1=int(s1[2]-'A'+1);
			l2=int(s2[2]-'A'+1);
			if((l1<=3 && l2<=3) || (l1>3 && l2>3)){
				cout<<'1';
				if(abs(l1-l2)==1) cout<<'1';
				else cout<<'0';
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
} 
