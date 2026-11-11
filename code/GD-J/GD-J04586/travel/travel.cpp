#include <bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2) cout<<"0000";
	else{
		cout<<"1";
		if(s1[0]+s1[1]!=s2[0]+s2[1]){
			cout<<"000";
		}else{
			cout<<"1";
			if(('A'<=s1[2] and s1[2]<='C' and 'A'<=s2[2] and s2[2]<='C') or ('D'<=s1[2] and s1[2]<='E' and 'D'<=s2[2] and s2[2]<='E')){
				cout<<"1";
				if(abs(s1[2]-s2[2])==1) cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
