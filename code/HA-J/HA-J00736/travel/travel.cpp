#include<bits/stdc++.h>

using namespace std;
int c1,s1,c2,s2,q,w;
char a,b;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>a>>c2>>s2>>b;
	q=int(a-'A'+1);
	w=int(b-'A'+1); 
	//cout<<c1<<' '<<s1<<' '<<q<<' '<<c2<<' '<<s2<<' '<<w<<' '<<endl;
	bool b=c1==c2;
	cout<<b;
	b=(b?s1==s2:0);
	cout<<b;
	b=(b?(q<4&&w<4||q>3&&w>3):0);
	cout<<b;
	b=(b?abs(q-w)==1:0);
	cout<<b;
	return 0;
}

