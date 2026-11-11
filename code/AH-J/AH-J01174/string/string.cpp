#include<bits/stdc++.h>
using namespace std;
long long n,a[2000000],len=0;
char b[2000000];
int main(){
  freopen("string.in","r",stdin);
  freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }if(n==2){
        if(b[1]==b[2]){
            cout<<0;
            return 0;
        }
        cout<<min(a[1],a[2]);
        return 0;
    }
    for(int i=1,j=n;i<j;i++,j--){
        if(a[i]==a[j]&&b[i]!=b[j]){
            len+=min(a[i],a[j]);
        }else if((a[i]!=a[j]&&b[i]!=b[j])||(a[i]!=a[j]&&b[i]==b[j])){
            len+=max(a[i],a[j])-min(a[i],a[j]);
            int d=max(a[i],a[j])-min(a[i],a[j]);
            len+=d;
            int i1;
            if(a[i]>a[j]){
                i1=a[j];
            }else{
                i1=a[i];
            }
            while(d>0){
                a[i1-1]-d;
                if(a[i1-1]>0){
                    break;
                }else{
                    d=abs(a[i1-1]);
                }
            }
        }
    }
    cout<<len;
    return 0;
}
