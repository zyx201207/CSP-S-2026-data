#include<iostream>
#include<string>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
    }else{
        for(int i=0;i<4;i++){
        	cout<<0;
        }
        return 0;
    } 
    string a1=s1,a2=s2;
    if(a1[0]==a2[0]&&a1[1]==a2[1]){
    	cout<<1;
    }else{
        for(int i=0;i<3;i++){
        	cout<<0;
        }
        return 0;
    }
     if(a1[2]=='C'&&a2[2]=='D'||a1[2]=='D'&&a2[2]=='C'){
    	for(int i=0;i<2;i++){
        	cout<<0;
        }
        return 0;
    }else{
    	if(a1[2]-a2[2]<=2&&a1[2]<='C'||a1[2]-a2[2]<=2&&a2[2]>='D'||a1[2]-a2[2]>=-2&&a2[2]<='C'||a1[2]-a2[2]>=-2&&a1[2]>='D'){
    	cout<<1;
        }else{
        	for(int i=0;i<2;i++){
        	    cout<<0;
            }
            return 0;
        }
    }
    if(a1[2]-a2[2]==1||a1[2]-a2[2]==-1){
    	cout<<1;
    }else{
    	for(int i=0;i<1;i++){
        	cout<<0;
        }
        return 0;
    }
	
    return 0;
}
