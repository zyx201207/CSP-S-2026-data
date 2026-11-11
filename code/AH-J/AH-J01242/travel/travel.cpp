#include<bits/stdc++.h>
using namespace std;
char b,c,d,f,g,h;
string a,e;
int x[5];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d>>e>>f>>g>>h;
    if(a==e){
        x[1]=1;
    }
    if(b==f&&c==g){
        x[2]=1;
    }
    if((d=='A'&&h=='B')||(d=='A'&&h=='C')||(d=='B'&&h=='C')||(d=='D'&&h=='F')||(d=='B'&&h=='A')||(d=='C'&&h=='A')||(d=='C'&&h=='B')||(d=='F'&&h=='D')){
        x[3]=1;
    }
    if((d=='A'&&h=='B')||(d=='B'&&h=='C')||(d=='D'&&h=='F')||(d=='B'&&h=='A')||(d=='C'&&h=='B')||(d=='F'&&h=='D')){
        x[4]=1;
    }
    for(int i=1;i<=4;i++){
        cout<<x[i];
    }
    return 0;
}
