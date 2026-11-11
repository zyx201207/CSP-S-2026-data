#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    int c=0;
    if (c1 == c2){
        c += 1000;
        if (s1[0]==s2[0]&&s1[1]==s2[1]){
            c+= 100;
        }
        if (s1[2]=='A'&&s2[2]=='B'){
            c+= 10;
            c++;
        }
        if (s1[2]=='B'&&s2[2]=='A'){
            c+= 10;
            c++;
        }
        if (s1[2]=='B'&&s2[2]=='C'){
            c+= 10;
            c++;
        }
        if (s1[2]=='C'&&s2[2]=='B'){
            c+= 10;
            c++;
        }
        if (s1[2]=='A'&&s2[2]=='C'){
            c+= 10;
        }
        if (s1[2]=='C'&&s2[2]=='A'){
            c+= 10;
        }
        if (s1[2]=='D'&&s2[2]=='F'){
            c+= 10;
            c++;
        }
        if (s1[2]=='F'&&s2[2]=='D'){
            c+= 10;
            c++;
        }

    }


    cout << c << endl;
    return 0;
}
