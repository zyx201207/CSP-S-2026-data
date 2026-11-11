#include<iostream>
#include<cstdio>
using namespace std;

int c1,r1,c2,r2;
char s1,s2;
bool check[4] = {};
int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("travel.in","r",stdin);
    freopen("trave1.out","w",stdout);

    cin >> c1 >> r1 >> s1;
    cin >> c2 >> r2 >> s2;



    if(c1 != c2){
        goto ret;
    }
    check[0]=1;
    if(r1 != r2){
        goto ret;
    }
    check[1]=1;
    if(s1<='C'&&s2>='D' || s1>='D'&&s2<='C'){
        goto ret;
    }
    check[2]=1;
    if(abs(s1-s2) != 1){
        goto ret;
    }
    check[3]=1;

    ret:

    for(int i=0;i<4;i++){
        cout << check[i];
    }


    cout << endl;

    fclose(stdin);
    fclose(stdout);

    return 0;
}



