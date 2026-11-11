#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string str1,str2;
    cin>>c1>>str1>>c2>>str2;
    int x1=int(str1[0]-'0');
    int x2=int(str1[1]-'0');
    int s1=x1*10+x2;
    x1=int(str2[0]-'0');
    x2=int(str2[1]-'0');
    int s2=x1*10+x2;
    if(c1==c2){
        cout<<1;
        if(s1==s2){
            cout<<1;
            int y1=int(str1[2]-'D');
            int y2=int(str2[2]-'D');
            //cout<<endl<<y1<<" "<<y2;
            if((y1>=0&&y2>=0)||(y1<0&&y2<0)){
                cout<<1;
                //cout<<abs(y1-y2);
                if(abs(y1-y2)==1){
                    cout<<1;
                }else{
                    cout<<0;
                }
            }else{
                cout<<"00";
            }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }

    return 0;
}
