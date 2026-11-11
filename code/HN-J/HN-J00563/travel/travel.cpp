#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	
	if(c1!=c2) cout<<0<<0<<0<<0;
	else{
		cout<<1;
		if(s1[0]!=s2[0]&&s1[1]!=s2[1]) {
			cout<<0<<0<<0;
		}
		else{
			cout<<1;
			if((s2[2]<='C'&&s1[2]>'C')||(s2[2]>='D'&&s1[2]<'D')){
				cout<<0<<0;
			}
			else{
				cout<<1;
				int n1=int(s1[2]);
				int n2=int(s2[2]);
				if(n1+1==n2||n1-1==n2) cout<<1;
				else cout<<0;
			}
		}	
	}
	return 0;
}

/*
02 01A 02 01B
*/
