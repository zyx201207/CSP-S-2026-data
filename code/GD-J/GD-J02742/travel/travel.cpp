#include<bits/stdc++.h>
using namespace std;
int c,c1;
string s,s1;
bool pan(string t){
	char w=t[2];
	if(w>='A'&&w<='C') return true;
	return false;
}
bool pan1(string a,string a1)
{
	int w=a[2],w1=a1[2];
	if(w>w1) swap(w,w1);
	if(w+1==w1) return true;
	return false;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>c>>s>>c1>>s1;
    if(c==c1)
    {
        cout<<"1";
        if(s.substr(0,2)==s1.substr(0,2)){
        	cout<<"1";
        	if(pan(s)==pan(s1)){
        		cout<<"1";
        		if(pan1(s,s1)==true){
        			cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
    }
    else{
        cout<<"0000";
    }
    return 0;
}
