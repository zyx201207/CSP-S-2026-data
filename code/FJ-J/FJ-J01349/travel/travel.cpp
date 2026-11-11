#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,t1,t2;
	cin>>s1>>t1>>s2>>t2;
	int tr1=(s1[0]-'0')*10+(s1[1]-'0');
	int tr2=(s2[0]-'0')*10+(s2[1]-'0');
	if(tr1!=tr2) cout<<"0000\n";
	else{
		int p1=(t1[0]-'0')*10+(t1[1]-'0');
		int p2=(t2[0]-'0')*10+(t2[1]-'0');
		if(p1!=p2) cout<<"1000\n";
		else{
			int w1=t1[2]-'A'+1;
			int w2=t2[2]-'A'+1;
			bool f1=(w1>3);
			bool f2=(w2>3);
			if(f1^f2) cout<<"1100\n";
			else{
				if(f1&&f2) cout<<"1111\n";
				else if(abs(w1-w2)==1) cout<<"1111\n";
				else cout<<"1110\n";
			}
		}
	}
}

