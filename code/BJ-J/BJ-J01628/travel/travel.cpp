#include<bits/stdc++.h>
#define F(i,a,b) for(int i = (a);i <= (b);i++)
#define D(i,a,b) for(int i = (a);i >= (b);i--)
using namespace std;
const int N = 1000;
int a,c;
string b,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<1;
        if(b.substr(0,2) == d.substr(0,2)){
            cout<<1;
            if((b[2] == 'A' && d[2] == 'B')||(b[2] == 'B' && d[2] == 'A')||(b[2] == 'C' && d[2] == 'B')||(b[2] == 'B' && d[2] == 'C')||(b[2] == 'D' && d[2] == 'F')||(b[2] == 'F' && d[2] == 'D')||(b[2] == 'A' && d[2] == 'C')||(b[2] == 'C' && d[2] == 'A')){
                cout<<1;
                if((b[2] == 'A' && d[2] == 'B')||(b[2] == 'B' && d[2] == 'A')||(b[2] == 'C' && d[2] == 'B')||(b[2] == 'B' && d[2] == 'C')||(b[2] == 'D' && d[2] == 'F')||(b[2] == 'F' && d[2] == 'D')){
                    cout<<1<<endl;
                }else{
                    cout<<"0\n";
                }
            }else{
                cout<<"00\n";
            }
        }else{
            cout<<"000\n";
        }
    }else{
        cout<<"0000\n";
    }
    return 0;
}
