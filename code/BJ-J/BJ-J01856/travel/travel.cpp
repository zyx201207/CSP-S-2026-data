#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define ll long long
#define pb push_back
#define fir first
#define sec second
const int N=2e5+7;
string s1,s2,c1,c2;
bool check(char a,char b){
    if(a=='D' || a=='E'){
        if(b=='D' || b=='E'){
            return 1;
        }
        return 0;
    }else{
        if(b!='D' && b!='E'){
            if(a=='A' && b=='C'){
                return 0;
            }else if(a=='C' && b=='A'){
                return 0;
            }
            return 1;
        }
        return 0;
    }
}
bool Check(char a,char b){
	if(a=='D' || a=='E'){
        if(b=='D' || b=='E'){
            return 1;
        }
        return 0;
    }else{
        if(b!='D' && b!='E'){
            return 1;
        }
        return 0;
    }
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
        string S1;
        S1+=s1[0]+s1[1];
        string S2;
        S2+=s2[0]+s2[1];
        if(S1==S2){
            cout<<1;
            if(check(s1[2],s2[2])){
                cout<<11;
            }else{
				if(Check(s1[2],s2[2])){
					cout<<"10";
				}else{
					cout<<"00";
				}
            }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }
    return 0;
}
