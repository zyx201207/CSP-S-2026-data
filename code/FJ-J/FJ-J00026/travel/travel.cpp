#include<bits/stdc++.h>
using namespace std;
int a[100];
string c1,c2,s1,s2;
int main(){
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	a['A'] = 1;
	a['B'] = 2;
	a['C'] = 3;
	a['D'] = 5;
	a['F'] = 6;
	if(c1==c2) {
		cout<<1;
		if(s1[0] == s2[0] &&s1[1]==s2[1]){
			cout<<1;
			if((a[s1[2]]<4 && a[s2[2]]<4)||(a[s1[2]]>4 && a[s2[2]]>4)){
				cout<<1;
				if((a[s1[2]]+1==a[s2[2]])||(a[s1[2]]-1==a[s2[2]]))
					cout<<1;
				else
					cout<<0;
			}
			else
				cout<<"00";
		}
		else
			cout<<"000";
		
	}
	else cout<<"0000";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
