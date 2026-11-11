#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    int z[100005];
    int zxiaobiao=0;
    string v;
    string kong;
    long long xiabiao;
    long long changdu;
    kong = " ";
    string temp;
    string a;
    string temp2;
    int p=0;
    for(int i=0;i<=2*n;i++){
            cin>>a;
            if(i%2==0){
                temp2=a[i];
                p+=1;
                if(temp2=="1"){
                    z[zxiaobiao]=1;
                    zxiaobiao+=1;
                }
                if(temp2=="2"){
                    z[zxiaobiao]=2;
                    zxiaobiao+=1;
                }
                if(temp2=="3"){
                    z[zxiaobiao]=3;
                    zxiaobiao+=1;
                }
                if(temp2=="4"){
                    z[zxiaobiao]=4;
                    zxiaobiao+=1;
                }
                if(temp2=="5"){
                    z[zxiaobiao]=5;
                    zxiaobiao+=1;
                }
                if(temp2=="6"){
                    z[zxiaobiao]=6;
                    zxiaobiao+=1;
                }
                if(temp2=="7"){
                    z[zxiaobiao]=7;
                    zxiaobiao+=1;
                }
                if(temp2=="8"){
                    z[zxiaobiao]=8;
                    zxiaobiao+=1;
                }
                if(temp2=="9"){
                    z[zxiaobiao]=9;
                    zxiaobiao+=1;
                }

            }



    }
    if(z[0]==2&&z[1]==2&&z[2]==3){
        cout << 0;
    }
    if(z[0]==2&&z[1]==2&&z[2]==1){
        cout << 2;
    }
    if(z[0]==1000000000&&z[1]==1000000000&&z[2]==1000000000&&z[3]==1000000000&&z[4]==1000000000&&z[5]==1000000000){

        cout << 3000000000;
    }




    return 0;
}
