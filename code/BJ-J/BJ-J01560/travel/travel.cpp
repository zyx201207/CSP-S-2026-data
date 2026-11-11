#include<bits/stdc++.h>
using namespace std;
int R_chexiang,X_chexiang;
string R_zuowei,X_zuowei;
int R_pai,X_pai;
char R_zuo,X_zuo;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>R_chexiang>>R_zuowei>>X_chexiang>>X_zuowei;
    if(R_chexiang!=X_chexiang)
    {
        cout<<"0000";
        return 0;
    }
    else if(R_chexiang==X_chexiang)
    {
        cout<<"1";
    }
    //
    R_pai=(R_zuowei[0]-'0')*10+(R_zuowei[1]-'0');
    X_pai=(X_zuowei[0]-'0')*10+(X_zuowei[1]-'0');
    if(R_pai!=X_pai)
    {
        cout<<"000";
        return 0;
    }
    else if(R_pai==X_pai)
    {
        cout<<"1";
    }
    //
    int R_guodao=0,X_guodao=0;
    if(R_zuowei[2]=='A'||R_zuowei[2]=='B'||R_zuowei[2]=='C')
    {
        R_guodao=1;
    }
    else if(R_zuowei[2]=='D'||R_zuowei[2]=='E')
    {
        R_guodao=2;
    }
    if(X_zuowei[2]=='A'||X_zuowei[2]=='B'||X_zuowei[2]=='C')
    {
        X_guodao=1;
    }
    else if(X_zuowei[2]=='D'||X_zuowei[2]=='E')
    {
        X_guodao=2;
    }
    if(R_guodao!=X_guodao)
    {
        cout<<"00";
        return 0;
    }
    else if(R_guodao==X_guodao)
    {
        cout<<"1";
    }
    //AB BA BC CB  DE ED
    R_zuo=R_zuowei[2];
    X_zuo=X_zuowei[2];
    if(R_zuo=='A'&&X_zuo=='B'){cout<<"1";}
    else if(R_zuo=='B'&&X_zuo=='A'){cout<<"1";}
    else if(R_zuo=='B'&&X_zuo=='C'){cout<<"1";}
    else if(R_zuo=='C'&&X_zuo=='B'){cout<<"1";}
    else if(R_zuo=='D'&&X_zuo=='E'){cout<<"1";}
    else if(R_zuo=='E'&&X_zuo=='D'){cout<<"1";}
    else {cout<<"0";}
    return 0;
}
