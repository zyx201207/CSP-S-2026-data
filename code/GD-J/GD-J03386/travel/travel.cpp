#include<bits/stdc++.h>
using namespace std;
int n1,n2;
string s1,s2;
int main(){
	    freopen("travel.in","r",stdin);
		freopen("travel.out","w",stdout);
        cin >> n1 >> s1>>n2>>s2;
        if(n1==n2){

        }
        else{
            cout << "0000";
            return 0;
        }
        if(s1[0]==s2[0]&&s1[1]==s2[1]){

        }
        else{
            cout << "1000";
            return 0;
        }
        if(((s1[2]=='F')||(s1[2]=='D'))&&((s1[2]=='F')||(s1[2]=='D'))){

        }
        else if(((s1[2]=='A')||(s1[2]=='B')||(s1[2]=='C'))&&((s2[2]=='A')||(s2[2]=='B')||(s2[2]=='C'))){

        }
        else{
            cout << "1100";
            return 0;
        }
        if(s1[2]+1==s2[2]||s1[2]-1==s2[2]){
            cout << "1111";
        }
        return 0;
}
