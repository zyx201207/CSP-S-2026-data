#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,yyy,qwqeeqew;
    string sans,c;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >>yyy>>c;
        for(int j=1;j<=yyy;j++){
            sans +=c;
        }
    }
    int qq=sans.size();
    for(int i=0;i<qq;i++){
        if(qq%2==1){
            if(i==(i+qq-1)/2){
            break;
            }
        }
        if(sans[i]!=sans[qq-i]){
            qwqeeqew++;
        }
    }
    cout << qwqeeqew;

    return 0;
}
