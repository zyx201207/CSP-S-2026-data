#include <bits/stdc++.h>
using namespace std;
char s[999999999],s1[999999999];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    scanf("%d",&n);
    int a,si=0;char c;
    for(int i=0;i<n;i++){
        scanf("%d %c",&a,&c);
        for(int j=si;j<si+a;j++){
            s[j]=c;
        }
        si+=a;
    }
    for(int i=0;i<=si;i++){
        s1[i]=s[si-i-1];
    }
    bool b=true;
    for(int i=0;i<si;i++){
        if(s[i]!=s1[i]){
            b=false;
            break;
        }
    }
    if(b) printf("0");
    else  printf("%d",si/2);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
