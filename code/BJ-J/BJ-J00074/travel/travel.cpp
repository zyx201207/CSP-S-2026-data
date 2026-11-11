#include<bits/stdc++.h>

using namespace std;

struct node{
    string s, c;
};

node a, b;

bool flag;

int lena, lenb;

string x = "", y = "";

int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> a.s >> a.c >> b.s >> b.c;

    if(a.s == b.s)
        cout << 1;
    else{
        cout << "0000";
        return 0;
    }

    lena = a.c.size();

    for(int i = 0; i < lena - 1; i++)
        x += a.c[i];

    lenb = b.c.size();

    for(int i = 0; i < lenb - 1; i++)
        y += b.c[i];

    if(x != y){
        cout << "000";
        return 0;
    }
    else
        cout << 1;

    if(a.c[lena - 1] == 'A' || a.c[lena - 1] == 'B' || a.c[lena - 1] == 'C'){
        if((b.c[lenb - 1] == 'A' || b.c[lenb - 1] == 'B' || b.c[lenb - 1] == 'C') && b.c[lenb - 1] != a.c[lena - 1]){
            cout << 1;
            flag = true;
        }
    }
    if(a.c[lena - 1] == 'D' || a.c[lena - 1] == 'F'){
        if((b.c[lenb - 1] == 'D' || b.c[lenb - 1] == 'F') && b.c[lenb - 1] != a.c[lena - 1]){
            cout << 1;
            flag = true;
        }
    }

    if(!flag){
        cout << "00";
        return 0;
    }

    if(a.c[lena - 1] == 'A' && b.c[lenb - 1] == 'B')
        cout << 1;
    else if(a.c[lena - 1] == 'B' && b.c[lenb - 1] == 'A')
        cout << 1;
    else if(a.c[lena - 1] == 'B' && (b.c[lenb - 1] == 'A' || b.c[lenb - 1] == 'C'))
        cout << 1;
    else if(b.c[lenb - 1] == 'B' && (a.c[lena - 1] == 'A' || a.c[lena - 1] == 'C'))
        cout << 1;
    else if(a.c[lena - 1] == 'C' && b.c[lenb - 1] == 'B')
        cout << 1;
    else if(a.c[lena - 1] == 'B' && b.c[lenb - 1] == 'C')
        cout << 1;
    else if(a.c[lena - 1] == 'D' && b.c[lenb - 1] == 'F')
        cout << 1;
    else if(a.c[lena - 1] == 'F' && b.c[lenb - 1] == 'D')
        cout << 1;
    else
        cout << 0;

    cout << endl;

    return 0;
}