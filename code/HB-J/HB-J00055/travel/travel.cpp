#include<bits/stdc++.h>
using namespace std;
bool in(char r,char* x){
    char now = x[0];
    int m = 1;
    while(now != '\0'){
        if(now == r){
            return 1;
        }
        now = x[m];
        m++;
    }
    return 0;

}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2){
        cout << 1;
        int rr = 10*(s1[0] - '0') + s1[1] - '0',xr = 10*(s2[0] - '0') + s2[1] - '0';
        if(rr == xr){
            cout << 1;
            char pr = s1[2],px = s2[2];
            char l[5] = {'A','B','C'};
            char r[5] = {'D','F'};
            if(in(pr,l) == in(px,l) || in(pr,r) == in(px,r)){
                cout << 1;
                if(abs(pr-px) == 1){
					cout << 1;
				}
				else{
					cout << 0;
				}
            }
            else{
                cout << "00";
            }
        }
        else{
            cout << "000";
        }
    }
    else{
        cout << "0000";
    }
}
