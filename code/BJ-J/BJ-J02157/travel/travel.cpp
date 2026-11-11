#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d,f,g,h,i,cont,e,j,k,l;
    cin >> a >> b >> c >> d;
    f=b(0);
    g=b(1);
    h=d(0);
    i=d(1);
    if(a==c)//两张车票对应的座位是否在同一节车厢
    {
        e+=1;
    }
    else{
        e+=0;
    }
    if(a==c && f==h)//两张车票对应的座位是否在同一节车厢的同一排
    {
        j+=1;
    }
    else{
        j+=0;
    }
    if((g="A" || g="B" || g="C")&&(i="A" || i = "B"|| i= "C"))//两张车票对应的座位是否在同一节车厢的同一排,且位于过道的同一侧
    {
        k += 1;
    }
    else if((g="D" || g="E")&&(i="D" || i = "E")){
        k += 1;
    }
    else{
        k += 0;
    }
    if((g="A"&&i="B")||(g="B"&&i="C")||(g="D"&&i="F"))//两张车票对应的座位是否相邻
    {
        l += 1;
    }
    else if((i="A"&&g="B")||(i="B"&&g="C")||(i="D"&&g="F")){
        l += 1;
    }
    else{
        l += 0;
    }
    count = e + j + k + l;
    cout << cont;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
