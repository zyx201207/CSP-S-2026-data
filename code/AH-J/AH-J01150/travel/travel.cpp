#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<0;
    }
    else cout<<1;
    string u=s1.substr(0,s1.size()-1);
    string v=s2.substr(0,s2.size()-1);
    if(c1==c2 && u==v)
    {
		cout<<1;
	}
    else cout<<0;
    if(c1==c2 && u==v && ((s1[s1.size()-1]<'D' && s2[s2.size()-1]<'D') || (s1[s1.size()-1]>'C' && s2[s2.size()-1]>'C')))
    {
		cout<<1;
	}
    else cout<<0;
    if(c1==c2 && u==v && ((s1[s1.size()-1]<'D' && s2[s2.size()-1]<'D' && abs(s1[s1.size()-1]-s2[s2.size()-1])==1) || (s1[s1.size()-1]>'C' && s2[s2.size()-1]>'C')))
    {
		cout<<1;
		//cout<<s1[s1.size()-1]<<"  "<<s2[s2.size()-1];
	}
    else cout<<0;
    //cout<<s1[s1.size()-1]<<"  "<<s2[s2.size()-1];
    return 0;
}
