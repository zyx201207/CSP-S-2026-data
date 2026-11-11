 #include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,c;
    char d[10];
    char b[10];
    cin>>a;
    cin>>b;
    cin>>c;
    cin>>d;
    if(a==c){
            cout<<"1";
       if(b[0]==d[0]&&b[1]==d[1]){
           cout<<"1";
        if(b[2]-d[2]<=2||d[2]-b[2]<=2){
            cout<<"1";
            if(b[2]-d[2]==1||d[2]-b[2]==1){
               cout<<"1";
            }
            else{
                cout<<"0";
            }

        }
        else{
            cout<<"0";
        }
       }
       else{
        cout<<"0";
       }
    }
    else{
        cout<<"0";
    }
return 0;
}
