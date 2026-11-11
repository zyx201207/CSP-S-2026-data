#include<bits/stdc++.h>
using namespace std;
int main ()
{
    freopen("travel.in",'r',stdin);
    freopen("travel.out",'w',stdout);
    int n,m;
    string a,b;
    cin>>n>>a>>m>>b;
    if (n==m){
        cout<<1;
    }else{
        cout << 0;
    }
    if(a[1]==b[1]&&a[2]==b[2]){
        cout<<1;
    }else{
        cout << 0;
    }
    if(a[1]==b[1]&&a[2]==b[2]){
        if(a[3]=='A'){
            if(b[3]=='B'||b[3]=='C'){
                cout << 1;
            }  
        }
        if(a[3]=='B'){
            if(b[3]=='A'||b[3]=='C'){
                cout << 1;
            }
        }
        if(a[3]=='C'){
            if(b[3]=='B'||b[3]=='A'){
                cout << 1;
            }
        }
        if(a[3]=='D'){
            if(b[3]=='E'){
                cout << 1;
            }
        }
        if(a[3]=='E'){
            if(b[3]=='D'){
                cout << 1;
            }
        }
    }else{
        cout << 0;
    }
    if(a[1]==b[1]&&a[2]==b[2]){
        if(a[3]=='A'){
            if(b[3]=='B'){
                cout << 1;
            }
        }
        if(a[3]=='B'){
            if(b[3]=='A'||b[3]=='C'){
                cout << 1;
            }
        }
        if(a[3]=='C'){
            if(b[3]=='B'){
                cout << 1;
            }
        }
        if(a[3]=='D'){
            if(b[3]=='E'){
                cout << 1;
            }
        }
        if(a[3]=='E'){
            if(b[3]=='D'){
                cout << 1;
            }
        }
    }else{
        cout << 0;
    }
    return 0;
}
