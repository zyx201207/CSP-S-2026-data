#include <iostream>

using namespace std;
bool cx,p,l,z;
int main()
{   freopen("travel.in","w",stdin)
    freopen("travel.out","r",stdout)

    int c_r,c_x;
    char s_r[3],s_x[3];
    cin>>c_r>>s_r>>c_x>>s_x;
    if(c_r==c_x){
        cx=1;
        if(s_r[0]==s_x[0]&&s_r[1]==s_x[1]){
            p=1;
            if(((s_r[2]-'0'==48)||(s_r[2]-'0'==49)||(s_r[2]-'0'==50))&&((s_x[2]-'0'==48)||(s_x[2]-'0'==49)||(s_x[2]-'0'==50))){
                l=1;
                if(((s_r[2]-'0')-(s_x[2]-'0')==1)||((s_r[2]-'0')-(s_x[2]-'0')==-1)){
                    z=1;
                    cout<<cx<<p<<l<<z;
                }
                else cout<<cx<<p<<l<<z;

            }
            else if(((s_r[2]-'0'==51)||(s_r[2]-'0'==52))&&((s_x[2]-'0'==51)||(s_x[2]-'0'==52))){
                l=1;
                if(((s_r[2]-'0')-(s_x[2]-'0')==1)||((s_r[2]-'0')-(s_x[2]-'0')==-1)){
                    z=1;
                    cout<<cx<<p<<l<<z;
                }
                else
                    cout<<cx<<p<<l<<z;
                }

            else{
                cout<<cx<<p<<l<<z;
            }
        }
        else{
            cout<<cx<<p<<l<<z;
        }
    }
    else{
        cout<<cx<<p<<l<<z;
    }

    fclose(stdin)
    fclose(stdout)
    return 0;
}
