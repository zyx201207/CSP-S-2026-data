#include<bits/stdc++.h>
using namespace std;
struct Ly{
    char pai11,pai12,pai21,pai22,pai1,pai2;
};
Ly ly1[20];
Ly ly2[20];
int main(){
    //freopen("travel.in","r",stdin);
    //freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<'1';//

        for(int i=0;i<3;i++){
            if(i==0){
                ly1[0].pai11=s1[0];
                ly2[0].pai21=s2[0];
            }
            else if(i==1){
                ly1[1].pai12=s1[1];
                ly2[1].pai22=s2[1];
                if(ly1[1].pai12==ly2[1].pai22&&ly1[0].pai11==ly2[0].pai21){
                    cout<<'1';//

                if(i==2){
                ly1[2].pai1=s1[2];
                ly2[2].pai2=s2[2];
                if(ly1[2].pai1=='A'||ly1[2].pai1=='B'||ly1[2].pai1=='C'&&ly2[2].pai2=='A'||ly2[2].pai2=='B'||ly2[2].pai2=='C'){
                    cout<<'1';//

                }
                else if(ly1[2].pai1=='D'||ly1[2].pai1=='F'&&ly2[2].pai2=='D'||ly2[2].pai2=='F'){
                    cout<<'1';
                }
                else if(ly1[2].pai1!='A'||ly1[2].pai1!='B'||ly1[2].pai1!='C'&&ly2[2].pai2=='A'||ly2[2].pai2=='B'||ly2[2].pai2=='C'||ly1[2].pai1=='A'||ly1[2].pai1=='B'||ly1[2].pai1=='C'&&ly2[2].pai2!='A'||ly2[2].pai2!='B'||ly2[2].pai2!='C'){
                    cout<<'0'<<'0';

                }
                if(ly1[2].pai1=='A'&&ly2[2].pai2=='B'||ly1[2].pai1=='B'&&ly2[2].pai2=='A'||ly1[2].pai1=='B'&&ly2[2].pai2=='C'||ly1[2].pai1=='C'&&ly2[2].pai2=='B'){
                    cout<<'1';
                }
                else if(ly1[2].pai1=='D'&&ly2[2].pai2=='F'||ly1[2].pai1=='F'&&ly2[2].pai2=='D'){
                    cout<<'1';
                }
                else {
                    cout<<'0';
                }
            }
    }
    else{
        cout<<'0'<<'0'<<'0';
    }
            }

    }
    }
    else{
        cout<<'0'<<'0'<<'0'<<'0';
    }



    return 0;
}
