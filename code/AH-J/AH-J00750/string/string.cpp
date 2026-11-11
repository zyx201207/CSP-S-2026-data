#include<bits/stdc++.h>
using namespace std;
long long n,s=0,a[200005];
char ch[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>ch[i];
    }
    int L=1,R=n;
    while(L<R){
        if(a[L]>=a[R]){
            if(ch[L]!=ch[R])s+=a[R];
            a[L]-=a[R];
            a[R]=0;
            //cout<<s<<'+'<<endl;
        }
        else{
            if(ch[L]!=ch[R])s+=a[L];
            a[R]-=a[L];
            a[L]=0;
            //out<<s<<'-'<<endl;
        }
        if(a[R]==0)R--;
        if(a[L]==0)L++;
    }
    cout<<s;

}
