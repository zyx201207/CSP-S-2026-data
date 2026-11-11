#include <bits/stdc++.h>
using namespace std;
long long n,m,cnt=0;
long long crs[1000005];
long long c[1000005],show[1000005];
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
cin>>n>>m;
long long ma=-9999999;
for(long long i=1;i<=n;i++){
    cin>>crs[i];
    if(c[i]==0){
        cnt++;
        show[cnt]=i;
    }
    c[i]++;
    if (c[i]>c[ma]){
        ma=i;
    }
}
sort(show+1,show+1+n);
long long mai,mas,num=c[ma];
for(long long i=1;i<=n;i++){
    if(ma==show[i]){
            mai=i;
            if(abs(show[mai]-show[mai-1])<abs(show[mai]-show[mai+1])){
                mas=abs(show[mai]-show[mai-1]);
                mai--;
                while(m>0){
                    m-=mas;
                    num++;
                }
                mai++;
            }
    }
            else{
                mas=abs(show[mai]-show[mai+1]);
                mai++;
                while(m>0){
                    m-=mas;
                    num++;
                }
                mai--;
            }
             break;
    }

cout<<num;
return 0;
}
