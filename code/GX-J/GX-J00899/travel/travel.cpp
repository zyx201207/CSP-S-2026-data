#include<iostream>
#include<cstring>
using namespace std;
bool tc(char aa,char bb)
{
    int dl=0,dr=0;
    if(aa-'A'<= 2) dl++;else dr++;
    if(bb-'A'<= 2) dl++;else dr++;
    return max(dl,dr)-1;
}
int main()
{
    freopen(travel.in,"w",std.in);
    freopen(travel.out,"r",std.out);
    int s=0;
    int a1,b1;
    string a2,b2;
    cin >> a1 >> a2 >> b1 >> b2;
    char a=a2[2],b=b2[2];
    if(a1==b1){
        s++;
        if(a2[0]==b2[0] && a2[1]==b2[1]){
            s++;
            int dl=0,dr=0;
            if(a-'A'<= 2) dl++;else dr++;
            if(b-'A'<= 2) dl++;else dr++;
            if(dr==2) s+=2;
            if(dl==2){
                s++;
                if(a-b==1 || b-a==1) s++;
            }
        }
    }
    //A-0=17
    for(int i=1;i <= s;i++) cout << 1;
    for(int i=s;i < 4;i++) cout << 0;
    return 0;
}
