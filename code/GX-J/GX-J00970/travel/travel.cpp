#include <bits/stdc++.h>
using namespace std;

int main(){
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    for(int i=1;i<100;i++){
        if(c1==c2){
            cout<<1;
            int n=s1%100;
            int t=s2%100;
            if(n==t){
                cout <<1;
            }
            else{
                    cout<<0;
            }
        }
        else{
            cout <<0;
        }

                int a=s1%10;
                int x=s2%10;
                if((a=="A"||a=="B"||a=="c")&&(x=="A"||x=="B"||x=="c"))
                        cout<<1;
                    if else{
                        if((a=="D"||a=="F")&&(x=="D"||x=="F"))
                                cout<<1;
                    }
                else{
                    cout<<0;
            }
                        int v=s1%1000;
                        int b=s2%1000;
                        if((v=="A",b=="B")||(b=="A",v=="B")||(v=="B",b=="C")||(b=="B",v=="C")||(v=="F",b=="D")||(b=="F",v=="D")){
                            cout<<1;
                        }else{
                            cout<<0;
                        }
    }
    return 0;
}
