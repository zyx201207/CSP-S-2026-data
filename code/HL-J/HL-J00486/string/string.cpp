#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int a,m=0;
    cin>> a;
    int n[a];
    char s[a],c;
    for(int i=0;i<=a-1;i++){
        cin>>n[i]>>s[i];


        m+=n[i];


    }
    //cout<<endl;cout<<endl;cout<<endl;cout<<endl;
   // for(int i=0;i<=a-1;i++){

   //     cout<<s[i];
   // }




    //cout<<endl;cout<<endl;cout<<endl;
    cout<<m/2;
     //cout<<0<<' '<<0<<' '<<0<<' '<<0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
//3
//2 a
//2 b
//1 c

