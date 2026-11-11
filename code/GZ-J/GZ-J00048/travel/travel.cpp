//GZ-J00048  赵晨希   贵阳市白云区第十四中学
#include<bits/stdc++.h>
using namespace std;
int a[6];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2;
    int c1,c2;
    cin>>c1>>s1>>c2>>s2;


    if(c1==c2){
        a[1]=1;
    if(s1[0]==s2[0]&&s1[1]==s2[1]){
        a[2]=1;
    if(abs(s1[2]-s1[2])!=1){
    	a[3]=1;
    	a[4]=1;
	}
    }
    }
    
	for(int i=1;i<=4;i++){
        cout<<a[i];
    }





    return 0;
}
