#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string  c1,s1,c2,s2;
    int a1=0,a2=0;
    cin>>c1>>s1>>c2>>s2;
    //weizhi
    if(c1==c2){
        cout<<"1";
        //yipai
        if(s1[1]==s2[1]){
            cout<<"1";
            a1=1;
        }
        else{
            cout<<"0";
        }
        if(a1==1){
            //yice
            if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
                if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
                    cout<<"1";
                    a2=1;
                }
                else{
                    cout<<"0";
                }
            }
            else{
                if(s2[2]=='F'||s2[2]=='D'){
                    cout<<"1";
                    a2=1;
                }
                else{
                    cout<<"0";
                }
            }
        }
        else{
            cout<<"0";
        }
        if(a1==1&&a2==1){
            //xianglin
            if(s1[2]=='A'&&s2[2]=='B'){
                cout<<"1";
            }
            else if(s1[2]=='B'){
                cout<<"1";
	        }
            else if(s1[2]=='C'&&s2[2]=='B'){
                cout<<"1";
            }
     	    else if(s1[2]=='F'||s2[2]=='D'){
                cout<<"1";
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
    else{
        cout<<"0000";
    }
    return 0;
}



