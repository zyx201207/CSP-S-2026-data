#include<bits/stdc++.h>
using namespace std;
int n;
struct Node{
    char s;
    int a;
};
bool chese(){
    for(int i=1,j=n;i<=n/2;i++,j--){
        if((num[i].a!=num[j].a)||(num[i].s!=num[j],s))return 0;
    }
    return 1;
}


Node num[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> num[i].a >> num[i].c;
        if(num[i].c==num[i-1].c){
            num[i-1].a+=num[i].a;
            i--;
            n--;
        }
    }
    int time=0;
    while(chese()==0){
        for(int i=1,j=n;i<=n/2;i++,j--){
            if((num[i].a!=num[j].a)||(num[i].s!=num[j],s)){
                if(num[i].a<num[j].a){
                    time+=num[i].a;
                    num[j-1].a+=num[j].a-num[i].a;
                    num[j].a=num[i].a;
                    num[j].s=num[i].s;
                }
                else{
                    time+=num[j].a;
                    num[i+1].a+=num[i].a-num[j].a;
                    num[i].a=num[j].a;
                    num[i].s=num[j].s;
                }
            }
        }
    }
    cout << time;
    return 0;
}
