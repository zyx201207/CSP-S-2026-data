#include<iostream>
#include<string>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b;
    int a1,b1;
    cin>>a1;
    cin>>a;
    cin>>b1;
    cin>>b;
    int w=1111;
    int d=1100;
    if(a1!=b1){
        cout<<"0000";
        return 0;
    }
    if(a[0]!=b[0]){
        cout<<"1000";
        return 0;
    }
    if(a[1]!=b[1]){
        cout<<"1000";
        return 0;
    }
    string s;
    s="ABCDF";
    if(a[2]==s[0]){
        if(b[2]==s[3]){
            cout<<d;
            return 0;
        }
        if(b[2]==s[4]){
            cout<<d;
            return 0;
        }
    }
    if(a[2]==s[1]){
        if(b[2]==s[3]){
            cout<<d;
            return 0;
        }
        if(b[2]==s[4]){
            cout<<d;
            return 0;
        }
    }
    if(a[2]==s[2]){
        if(b[2]==s[3]){
            cout<<d;
            return 0;
        }
        if(b[2]==s[4]){
            cout<<"1100";
            return 0;
        }
    }
    if(a[2]==s[3]){
        if(b[2]==s[0]){
            cout<<d;
            return 0;
        }
        if(b[2]==s[1]){
            cout<<d;
            return 0;
        }
        if(b[2]==s[2]){
            cout<<d;
            return 0;
        }
    }
    if(a[2]==s[4]){
        if(b[2]==s[0]){
            cout<<d;
            return 0;
        }
        if(b[2]==s[1]){
            cout<<d;
            return 0;
        }
        if(b[2]==s[2]){
            cout<<d;
            return 0;
        }
    }
    if(a[2]==s[0]){
        if(b[2]==s[1]){
            cout<<w;
            return 0;
        }
    }
    if(a[2]==s[1]){
        if(b[2]==s[0]){
            cout<<w;
            return 0;
        }
        if(b[2]==s[2]){
            cout<<w;
            return 0;
        }
    }
    if(a[2]==s[2]){
        if(b[2]==s[1]){
            cout<<w;
            return 0;
        }
    }
    if(a[2]==s[3]){
        if(b[2]==s[4]){
            cout<<w;
            return 0;
        }
    }
    if(a[2]==s[4]){
        if(b[2]==s[3]){
            cout<<w;
            return 0;
        }
    }
    cout<<"1110";
    return 0;
}
