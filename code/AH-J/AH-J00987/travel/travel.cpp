#include<iostream>
#include<string>
using namespace std;
string c1,c2,c3,c4;
string ans(){
    string ret;
    if(c1!=c3)
        return "0000";
    ret+='1';
    if(c2[0]==c4[0]&&c2[1]==c4[1]){
       ret+='1';
       if((c2[2]<='C'&&c4[2]<='C')||(c2[2]>='D'&&c4[2]>='D')){
          ret+='1';
          if(c2[2]-c4[2]==1||c2[2]-c4[2]==-1)
            return "1111";
          else
            return "1110";
        }else
            ret+="00";
     }else
        ret+= "000";
     return ret;
}

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>c2>>c3>>c4;
    cout<<ans();
    //fclose(stdin);fclose(stdout);
    return 0;
}
