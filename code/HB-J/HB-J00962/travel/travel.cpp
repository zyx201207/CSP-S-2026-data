#include<bits/stdc++.h>
using namespace std;
char s1[5],s2[5];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b;
    cin>>a;
    for(int i=0;i<3;i++){
    	cin>>s1[i];
    }
    cin>>b;
    for(int i=0;i<3;i++){
    	cin>>s2[i];
    }
    if(a==b){
    	cout<<1;
    	if(s1[0]==s2[0]&&s1[1]==s2[1]){
       		cout<<1;
       		if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')){
       			cout<<1;
       			if(int(s1[2])+1==int(s2[2])||int(s1[2]-1)==int(s2[2]))cout<<1;				else cout<<0;
       		}
       		else cout<<00;
       	}
       	else cout<<000;
    }
    return 0;
}
