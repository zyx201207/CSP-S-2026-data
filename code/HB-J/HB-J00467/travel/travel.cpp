#include<bits/stdc++.h>
using namespace std;
string b[2];
int a[2];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    for(int i=0;i<2;i++){
        cin>>a[i];
        cin>>b[i];
    }
    if(a[0]==a[1]){
        cout<<1;
    }
    else{
        cout<<0<<0<<0<<0;
        return 0;
    }
    string m=b[0],n=b[1];
    if(m[0]!=n[0]){
        cout<<0<<0<<0;
        return 0;
    }
    else{
        if(m[1]!=n[1]){
            cout<<0<<0<<0;
            return 0;
        }
        else{
            cout<<1;
            if(m[2]=='D'||m[2]=='F'){
                if(n[2]=='D'||n[2]=='F'){
                    cout<<11;
                    return 0;
                }
                else{
                    cout<<0<<0;
                    return 0;
                }
            }
            else{
                if(n[2]=='D'||n[2]=='F'){
                    cout<<0<<0;
                    return 0;
                }
                else{
                    cout<<1;
                    if(m[2]=='B'||n[2]=='B'){
                        cout<<1;
                        return 0;
                    }
                    else{
                        cout<<0;
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}
