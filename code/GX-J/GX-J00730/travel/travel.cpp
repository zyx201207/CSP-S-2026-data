#include<bits/stdc++.h>
using namespace std;

string R,r,X,x;





int main(){
fropen("travel.in","r",stdin);
fropen("travel.out","w",stdout);
cin>>R>>r>>X>>x;

string tain[20]{"01","02","03","04","05","06","07","08","09","10","11","12","13","14","15","16"};


    if(R==tain[0]||R==tain[15]||X==tain[0]||X==tain[15]){
        cout<<0;
    }
    else {
        cout<<1;
    }




return 0;
}
