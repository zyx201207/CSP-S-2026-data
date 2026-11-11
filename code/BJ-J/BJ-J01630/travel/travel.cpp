#include<iostream>
using namespace std;



int ab(int a,int b){
    if(a-b>=0){
        return a-b;
    }
    return b-a;

}
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char a[10],b[10];
    for(int i=1;i<=5;i++){
        cin>>a[i];
        //cout<<a[i];
    }
    cout<<endl;
    for(int i=1;i<=5;i++){
        cin>>b[i];
        //cout<<b[i];
    }
    int x=(int)a[5];
    int y=(int)b[5];
    if(a[1]==b[1]&&a[2]==b[2]){
        cout<<"1";
        if(a[3]==b[3] && a[4]==b[4]){
            cout<<"1";
            if((x>=int('D')&&y>=int('D'))||(x<=int('C')&&y<=int('C'))){
                cout<<"1";
                if(x>=int('D')&&y>=int('D')){
                    cout<<"1";
                }
                else if(ab(x,y)==1){
                    cout<<"1";
                }
                else cout<<"0";
            }
            else{
                cout<<"00";
            }
        }
        else{
            cout<<"000";
        }
    }
    else{
        cout<<"0000";
    }

    return 0;

}






















