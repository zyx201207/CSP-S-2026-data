#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;
int ans[10];





int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin>>c1>>s1>>c2>>s2;
    if(c1[0]!=c2[0]||c1[1]!=c2[1]){
        cout<<"0000";
        return 0;
    }

    if(s1[0]!=s2[0]||s1[1]!=s2[1]){
        cout<<"1000";
        return 0;
    }
    
    char x[5];
    if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')x[1]='r';
    else x[1]='l';
    if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')x[2]='r';
    else x[2]='l';

    if(x[1]!=x[2]){
        cout<<"1100";
        return 0;
    }

    if(s1[2]+1!=s2[2]&&s1[2]!=s2[2]+1){
        cout<<"1110";
        return 0;
    }

    cout<<"1111";

	return 0;
}

