#include<bits/stdc++.h>
using namespace std;
int n1,n2,m1,m2;
char s1[10],s2[10],c1[10],c2[10];
string s;
int main(){

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf("%s%s%s%s",s1+1,s2+1,c1+1,c2+1);
    n1=strlen(s1+1),n2=strlen(s2+1),m1=strlen(c1+1),m2=strlen(c2+1);
    bool ok=true;
    for(int i=1;i<=max(n1,m1);i++){
        if(s1[i]!=c1[i]){
            ok=false;
        }
    }
    if(ok){
        s+='1';
    }else{
        printf("0000\n");
        return 0;
    }
    ok=true;
    string t1,t2;
    int x1=0,x2=0;
    for(int i=1;i<=max(n2,m2);i++){
        if(s2[i]>='A'&&s2[i]<='Z'){
            x1=i;
            for(int j=1;j<i;j++){
                t1+=s2[j];
            }
        }
        if(c2[i]>='A'&&c2[i]<='Z'){
            x2=i;
            for(int j=1;j<i;j++){
                t2+=c2[j];
            }
        }
    }
    if(t1==t2){
        s+='1';
    }else{
        printf("1000\n");
        return 0;
    }
    if(s2[x1]<='C'&&c2[x2]<='C'){
        s+='1';
        if(abs(s2[x1]-'A'-(c2[x2]-'A'))==1){
            s+='1';
        }else{
            s+='0';
        }
    }else{
        if(s2[x1]>='D'&&c2[x2]>='D'){
            printf("1111\n");
        }else{
            printf("1100\n");
        }
        return 0;
    }
    printf("%s\n",s.c_str());

    return 0;
}
