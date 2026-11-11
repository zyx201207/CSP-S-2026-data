#include <iostream>

using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    bool FLAG=true;
    int train1,train2;
    string pos1,pos2;
    cin>>train1>>pos1>>train2>>pos2;
    if(train1==train2){
        cout<<1;
    }else{
        cout<<0;
        FLAG=false;
    }
    int col1=(pos1[0]-'0')*10+pos1[1]-'0';
    int col2=(pos2[0]-'0')*10+pos2[1]-'0';
    if((train1==train2) && col1==col2){
        cout<<1;
    }else{
        cout<<0;
        FLAG=false;
    }
    char color1=pos1[2];
    char color2=pos2[2];
    bool flagcolor=false;
    if((train1==train2) && (col1==col2) ){
        if( (color1=='D' && color2=='F') || (color1=='F'&&color2=='D') ){
            //cout<<1;
            flagcolor=true;
        }else if( color1=='A'){
            if(color2=='B' || color2=='C'){
                //cout<<1;
                flagcolor=true;
            }else{
            }
        }else if(color1=='B'){
            if(color2=='A' || color2=='C'){
                //cout<<1;
                flagcolor=true;
            }
        }else if(color1=='C'){
            if(color2=='B' || color2=='A'){
                //cout<<1;
                flagcolor=true;
            }
        }
    }
    if(flagcolor){
        cout<<1;
    }else{
    cout<<0;
    //FLAG=false;
    }
	flagcolor=false;
	if((train1==train2) && (col1==col2) ){
        if( (color1=='D' && color2=='F') || (color1=='F'&&color2=='D') ){
            //cout<<1;
            flagcolor=true;
        }else if( color1=='A'){
            if(color2=='B'){
                //cout<<1;
                flagcolor=true;
            }else{
            }
        }else if(color1=='B'){
            if(color2=='A' || color2=='C'){
                //cout<<1;
                flagcolor=true;
            }
        }else if(color1=='C'){
            if(color2=='B'){
                //cout<<1;
                flagcolor=true;
            }
        }
    }
	if(!flagcolor){
		FLAG=false;
	}
    if(FLAG){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}
