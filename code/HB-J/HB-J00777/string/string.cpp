#include<bits/stdc++.h>
using namespace std;

int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
long long L=0,ans=0;
int n;cin>>n;
char a[n+3];
int l[n+3];
for(int i=1;i<=n;i++){
    cin>>l[i]>>a[i];
    L+=l[i];
}
char x;
long long len;
int zlen=0,ylen=0;
for(int i=1;i<=ceil(n/2);i++){
        if(ylen!=0){
            if(x!=a[i]&&l[i]>=ylen){
                    ans+=l[i]-ylen;
           l[i]-=ylen;
                    ylen=0;
            }
            else ylen-=l[i];
        }
        if(zlen!=0){
            if(x!=a[n+1-i]&&l[n+1-i]>=zlen){
                    ans+=l[n+1-i]-zlen;
                    l[n+1-i]-=zlen;
                    zlen=0;
            }
            else zlen-=l[n+1-i];
        }
    if(a[i]!=a[n-i+1]){
        ans+=min(l[i],l[n+1-i]);
        if(l[i]>l[n+1-i]){
                zlen=l[i]-l[n+1-i];
        char x=a[i];
        }
        else {
                ylen=abs(l[i]-l[n+1-i]);
                 char x=a[n+1-i];
    }
    }
else{
        if(l[i]>l[n+1-i]){
                zlen=l[i]-l[n+1-i];
        char x=a[i];
        }
else {
                ylen=abs(l[i]-l[n+1-i]);
                 char x=a[n+1-i];
    }
}
}
if(L%2==1)ans+=1;
cout<<ans;
return 0;
}

