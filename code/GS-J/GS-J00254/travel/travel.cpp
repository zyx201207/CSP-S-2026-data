#include<bits/stdc++.h>
using namespace std;
string a,s,d,f;
bool q=0,w=0,e=0,r=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>a>>s>>d>>f;
    if(a!=d){
    	cout<<q<<w<<e<<r;
    	return 0;
	}
	q=1;
	if(s[0]==f[0]&&s[1]==s[1]){
		w=1;
	}
	if(w==1&&s[2]<68&&f[2]<68||w==1&&s[2]>67&&f[2]>67){
	   	e=1;
	}
	if(w==1&&e==1&& s[2]+1==f[2]||s[2]-1==f[2]){
	   	r=1;
	}
	cout<<q<<w<<e<<r;
    return 0;
}
