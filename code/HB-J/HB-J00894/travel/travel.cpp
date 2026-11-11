#include <iostream>
#include <string>
using namespace std;

int compare1(string a,string b){
    char ac=a[2],bc=b[2];
    if(((ac=='A')||(ac=='B')||(ac=='C'))&&((bc=='A')||(bc=='B')||(bc=='C'))){
        return 1;
    }
    else if(((ac=='D')||(ac=='F'))&&((bc=='D')||(bc=='F'))){
        return 1;
    }
    return 0;
}

int compare2(string a,string b){
    char ac=a[2],bc=b[2];
    if(ac=='A'&&bc=='B'){
       return 1;
    }
    else if((ac=='B'&&bc=='A')||(ac=='B'&&bc=='C')){
       return 1;
    }
    else if(ac=='C'&&bc=='B'){
       return 1;
    }
    else if(ac=='D'&&bc=='F'){
       return 1;
    }
    else if(ac=='F'&&bc=='D'){
       return 1;
    }
    return 0;
}
int main(){

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    string c1,s1,c2,s2,ans={};
    cin>>c1>>s1>>c2>>s2;

    if(c1==c2){
        ans[0]=1;
    }
    else{
        cout<<"0000"<<endl;
        return 0;
    }

    if(s1[0]==s2[0]&&s1[1]==s2[1]){
        ans[1]=1;
    }
    else{
        cout<<"1000"<<endl;
        return 0;
    }

    if(compare1(s1,s2)==1){
        ans[2]=1;
    }
    else{
        cout<<"1100"<<endl;
        return 0;
    }

    if(compare2(s1,s2)==1){
        ans[3]=1;
    }
    else{
        cout<<"1110"<<endl;
        return 0;
    }

    cout<<"1111"<<endl;

    fclose(stdin);
    fclose(stdout);

    return 0;
}
