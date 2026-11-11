#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,t1,t2;
    cin>>s1>>s2>>t1>>t2;
    if(s1==t1){
        printf("1");
        a=1;
    }else{
        printf("0");
    }
    string p="",q="";
    int o=s2.size();
    for(int i=0;i<o-1;i++){
        p+=s2[i];
        q+=t2[i];
    }
    if(a==1&&p==q){
        printf("1");
        b=1;
    }else{
        printf("0");
    }
    char m,n;
    m=s2[s2.size()-1],n=t2[t2.size()-1];
    if(b==1){
	    if((m>='A'&&m<='C'&&n>='A'&&n<='C')||(m=='D'&&n=='F')||(m=='F'&&n=='D')){
            printf("1");
            c=1;
	    }else{
		    printf("0");
		}
    }else{
        printf("0");
    }
    if(c==1){
		if(m+1==n||m-1==n||(m=='D'&&n=='F')||(m=='F'&&n=='D')){
             printf("1");
        }else{
             printf("0");
        }
	}else{
        printf("0");
    }
    return 0;
}
