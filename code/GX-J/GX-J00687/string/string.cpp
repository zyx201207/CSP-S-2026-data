#include<iostream>
using namespace std;
int main(){
     //freopen("string.in","r",stdin);
     //freopen("string.out","w",stdout);
     long long a,b;
     char s;
     int num=0;
     cin>>a;
     for(int i=0;i<a;i++){
        cin>>b>>s;
     }
     for(int i=0;i<=b;i++){
        if(s!='a'&&'b'){
            num++;
        }
     }
     cout<<num;
     return 0;
}
