#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
    }else{
        cout<<0;
    }
    if(c1==c2 && s1[0] == s2[0] && s1[1] == s2[1]){
        cout<<1;
    }else{
        cout<<0;
    }
    int s1t = 1;
    int s2t = 1; 
    char a[3] = {'A','B','C'};
    for(char i : a){
        if(s1[2] == i){
            s1t = 0;
        }
        if(s2[2] == i){
            s2t = 0;
        }
    }
    if(c1==c2 && s1[0] == s2[0] && s1[1] == s2[1] && s1t==s2t){
        cout<<1;
    }else{
        cout<<0;
    }
    bool qwer = c1==c2 && s1[0] == s2[0] && s1[1] == s2[1] && s1t==s2t;
    bool asdf = (s1[2] == 'A' && s2[2] == 'B') || (s1[2] == 'B' && s2[2] == 'A') || (s1[2] == 'B' && s2[2] == 'C') || (s1[2] == 'C' && s2[2] == 'B');
    if(qwer && (asdf||(s1[2] == 1 && s2[2] == 1))){
		cout<<1;
	}else{
		cout<<0;
	}
    return 0;
}
