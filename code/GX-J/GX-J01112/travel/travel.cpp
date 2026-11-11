#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string r;
    string x;
    int a;
    int b;
    cin>>a>>r>>b>>x;
    if(a==b){
        cout<<1;
        string n=r;
        string m=x;
        int c=n[0]*10+n[1];
        int d=m[0]*10+m[1];
        if(c==d){
            cout<<"1";
            if(n[2]+1==m[2]||n[2]-1==m[2]){
                if(n[2]!='C'||m[2]!='D'){
                    cout<<"11";
                }
                else{
                    cout<<"00";
                }
            }
            else if((n[2]=='D'&&m[2]=='F')||(n[2]=='F'&&m[2]=='D')){
                cout<<"11";
            }
            else if((n[2]=='A'&&m[2]=='C')||(n[2]=='C'&&m[2]=='A')){
                cout<<"10";
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
    fclose(stdin);
    fclose(stdout);
}
