#include<bits/stdc++.h>
using namespace std;
struct c{
    char b;
    int a;
}c[200005];
long long cnt, now_last;
char now_char;
bool lr;//0 l, 1 r
int ri;
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>c[i].a>>c[i].b;
    }
    lr=1;
    ri=n;
    for(int i=1;i<=n;){
        if(i>=ri){
            break;
        }
        if(now_last==0){
            now_char=c[i].b;
            now_last=c[i].a;
            lr=1;
        }
        while(i<ri){
            if(lr){
                if(c[ri].b==now_char){
                    if(c[ri].a>=now_last){
                        now_last=c[ri].a-now_last;
                        i++;

                        break;
                    }
                    else{
                        now_last-=c[ri].a;
                        ri--;
                    }
                }
                else{
                    if(c[ri].a>=now_last){
                        cnt+=now_last;
                        now_last=c[ri].a-now_last;
                        now_char=c[ri].b;
                        if(now_char==0)ri--;
                        i++;
                        break;
                    }
                    else{
                        cnt+=c[ri].a;
                        now_last-=c[ri].a;
                        ri--;
                    }
                }
            }
            else{
                if(c[i].b==now_char){
                    if(c[i].a>=now_last){
                        now_last=c[i].a-now_last;
                        ri--;

                        break;
                    }
                    else{
                        now_last-=c[i].a;
                        i++;
                    }
                }
                else{
                    if(c[i].a>=now_last){
                        cnt+=now_last;
                        now_last=c[i].a-now_last;
                        now_char=c[i].b;
                        if(now_char==0)i++;
                        ri--;
                        break;
                    }
                    else{
                        cnt+=c[i].a;
                        now_last-=c[i].a;
                        i++;
                    }
                }
            }
        }
        lr=!lr;
        if(ri-i==1&&now_last==0)break;
    }
    cout<<cnt;
    return 0;
}
