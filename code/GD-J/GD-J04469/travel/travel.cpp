#include<bits/stdc++.h>
using namespace std;

string c1,c2,s1,s2;
bool a1,a2,a3,a4;

int main(){
	
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);	
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c1>>s1>>c2>>s2;
	
	a1=(c1==c2);
	a2=(a1&&(s1[0]==s2[0])&&(s1[1]==s2[1]));	
	a3=(a2&&((s1[2]>='A'&&s1[2]<='C')==(s2[2]>='A'&&s2[2]<='C')));
	a4=(a3&&(((s1[2]+1)==s2[2])||((s1[2]-1)==s2[2])));
	
	cout<<a1<<a2<<a3<<a4;
	//cout<<endl<<s1<<" "<<s2;
	
	return 0;
}
