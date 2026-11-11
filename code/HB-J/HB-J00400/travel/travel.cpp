#include<bits/stdc++.h>
using namespace std;
char a[12];
int cnt=0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    for(int i=1;i<=10;i++){
        cin>>a[i];
    }
    if(a[1]==a[6]&&a[2]==a[7]){
        cout<<1;
        cnt++;
        if(a[3]==a[8]&&a[4]==a[9]){
            cout<<1;
            cnt++;
            if((a[5]=='A'&&a[10]=='B')||(a[5]=='A'&&a[10]=='C')||(a[5]=='B'&&a[10]=='A')||(a[5]=='B'&&a[10]=='C')||(a[5]=='C'&&a[10]=='A')||(a[5]=='C'&&a[10]=='B')||(a[5]=='D'&&a[10]=='F')||(a[5]=='F'&&a[10]=='D')){
                cout<<1;
                cnt++;
                if(a[5]-a[10]==1||a[10]-a[5]==1){
                   cout<<1;
                   cnt++;
                }
            }
        }
    }
    for(int i=1;i<=4-cnt;i++){
        cout<<0;
    }
    return 0;
}
