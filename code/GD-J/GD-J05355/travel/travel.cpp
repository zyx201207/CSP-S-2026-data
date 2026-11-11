#include<bits/stdc++.h>
using namespace std;

typedef long long ll;



int n,m;
string c1,c2,s1,s2;


int main(){
	freopen ("travel.in","r",stdin);
	freopen("travel.ans","w",stdout);
	//freopen("travel5.in","r",stdin);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>c1>>s1>>c2>>s2;
	
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C')){
				cout<<1;
			if(abs(s1[2]-s2[2])==1)
			cout<<1;
			else cout<<0;
		}
		else cout<<"00";
	}
	else cout<<"000";
}
else cout<<"0000";
	
	return 0;
} 
