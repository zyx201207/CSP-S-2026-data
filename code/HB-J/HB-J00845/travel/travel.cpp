#include<iostream>
using namespace std;

int c1, s1, m, m1;

int main(){
    //freopen("travel.in", "r", stdin);
    //freopen("travel.out", "w", stdout);


    string c2, s2;
    string n ="ABCDF";
    cin >> c1 >> c2 >> s1 >> s2;
    //两张车票对应的座位是否在同一节车厢
    if(c1 == s1){
        cout << 1;
        //两张车票对应的座位是否在同一节车厢的同一排;
        if(c2[0] == s2[0] && c2[1] == s2[1]){
            cout << 1;


            for(int i = 0; i < 5; i++){
                if(c2[2] == n[1]){
                    m = i;
                    break;
                }
            }
            for(int i1 = 0; i1 < 5; i1++){
                if(s2[2] == n[1]){
                    m1 = i1;
                    break;
                }
            }
            //两张车票对应的座位是否在同一节车厢的同一排,且位于过道的同一侧;
            if((m <= 2 && m1 <=2) || (m > 2 && m1 > 2)){
                cout << 1;
                //两张车票对应的座位是否相邻
                if(m + 1 == m1 || m - 1 == m1){
                    cout << 1;
                }else{
                    cout << 0;
                }

            }else{
                cout << 0 << 0;
            }

        }else{
            cout << 0 << 0 << 0;
        }

    }else{
        cout << 0 << 0 << 0 << 0;
    }


    //fclose(stdin);
    //fclose(stdout);
    return 0;

}
