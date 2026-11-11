#include<bits/stdc++.h>
using namespace std;
char s1[3],s2[3],c1[3],c2[3];
int a1,a2,a3,a4;
int main(){
    freopen("travle.in","r",stdin);
    freopen("travle.out","w",stdout);
    cin>>s1>>c1>>s2>>c2;
    a1 = 1;
    for(int i = 0;i < 2;i++){
        if(s1[i] != s2[i]){
            a1 = 0;
            break;
    }
    }
    a2 = 1;
    for(int i = 0;i < 2;i++){
        if(c1[i] != c2[i]) {
            a2 = 0;
        }
    }
    if(c1[2] == 'A'||c1[2] == 'B'||c1[2] == 'C'&&c2[2] == 'A'||c2[2] == 'B'||c2[2] == 'C') a3 = 1;
    else a3 = 0;
    if(c1[2] == 'D'||c1[2] == 'F'&&c2[2] == 'D'||c2[2] == 'F') a1 = 1;
    a4 = 0;
    if(c1[2] == 'A'&&c2[2] == 'B'||c1[2] == 'B'&&c2[2] == 'A'||c1[2] == 'C'&&c2[2] == 'B') a4 = 1;
    if(c1[2] == 'D'&&c2[2] == 'F'||c1[2] == 'F'&&c2[2] == 'D') a4 = 1;
    return 0;
    printf("%d%d%d%d",a1,a2,a3,a4);
}
