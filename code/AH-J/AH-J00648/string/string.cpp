#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,shu[20010],zz,yz,zy=0,he=0;
    long long s;
    string zimu[200010];
    cin>>n;
    zz=0,yz=n;
    for(int i=1;i<=n;i++){
        cin>>shu[i]>>zimu[i];
    }
    while(zz<yz){
        if(zy==0){
            if(he>=shu[yz]){
                if(zimu[zz]!=zimu[yz]){
                    s+=shu[yz];
                }else{
                }
                he-=shu[yz];
                yz--;
            }else{
                zy=1;
                if(zimu[zz]!=zimu[yz]){
                    s+=he;
                }else{
                }
                he=shu[yz]-he;
                zz++;
            }
        }else{
            if(he>=shu[zz]){
                if(zimu[zz]!=zimu[yz]){
                    s+=shu[zz];
                }else{
                }
                he-=shu[zz];
                zz++;
            }else{
                zy=0;
                if(zimu[zz]!=zimu[yz]){
                    s+=he;
                }else{
                }
                he=shu[zz]-he;
                yz--;
            }
        }
    }
    cout<<s;
    return 0;
}
