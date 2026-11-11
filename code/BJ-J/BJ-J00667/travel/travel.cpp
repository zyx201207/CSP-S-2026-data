#include<bits/stdc++.h>
using namespace std;
int car1,car2;
int row1,row2;
char seat1,seat2;
bool fcar,frow,fseat,fnear;

bool check(char a,char b){
    if(!fseat) return false;
    if(a>='D' && b>='D'){
        return true;
    }
    else {
        return abs((int)a-b)==1;
    }
}

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    fcar = frow = fseat = fnear = false;
    scanf("%d %d%c %d %d%c",&car1,&row1,&seat1,&car2,&row2,&seat2);
    fcar = (car1==car2);
    frow = fcar && (row1==row2);
    fseat = frow && ((seat1<='C'&&seat2<='C') || (seat1>='D'&&seat2>='D'));
    fnear = check(seat1,seat2);
    cout<<fcar<<frow<<fseat<<fnear<<endl;
    return 0;
}
