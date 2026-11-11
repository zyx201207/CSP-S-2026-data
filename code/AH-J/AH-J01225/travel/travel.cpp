#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int s1,c1;
    string s2,c2;
    cin>>s1>>s2>>c1>>c2;
    if(s1!=c1){
        cout<<"0000";
    }else{
        int row1=0,row2=0;
        char sit1=s2[2],sit2=c2[2];
        for(int i=0;i<2;i++){
            row1=row1*10+s2[i]-'0';
            row2=row2*10+c2[i]-'0';
        }
        if(row1!=row2){
            cout<<"1000"<<" "<<row1<<" "<<row2;
        }else{
            if(sit1>sit2) swap(sit1,sit2);
            if(sit1=='A'&&sit2=='B'||sit1=='B'&&sit2=='C'||sit1=='D'&&sit2=='F'){
                cout<<"1111";
            }else if(sit1=='A'&&sit2=='C'){
                cout<<"1110";
            }else{
                cout<<"1100";
            }
        }
    }
    return 0;
}

