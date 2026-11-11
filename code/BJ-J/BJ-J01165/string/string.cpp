#include<bits/stdc++.h>
using namespace std;
int n;
char chh[5];
struct{
    long long id;
    char a;
    int sum=0;
}num[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    int k=0;
    for(int i=1;i<=n;i++){
        cin>>num[i].id;
        cin>>num[i].a;
    }
    int jun=0;
    long long ans=0;
    int l=1,r=n,ch=0;
    bool b=false;
    while(l<=r){
        if(l==r){
            if(chh[1]!=num[l].a&&ch!=0){
                ans+=ch;
            }
            break;
        }
       if(b&&ch!=0){
        int check=ch-num[l].id;
           while(check){
                if(num[l].a!=chh[1]){
                    ans+=num[l].id;
                }
                l++;
            check-=num[l].id;
           }
           num[l].id=0-check;
       }
       if(!b&&ch!=0){
        int check=ch-num[r].id;
           while(check){
                r--;
            check-=num[r].id;
           }
           num[r].id=0-check;
       }
       if(num[l].id>num[r].id){
        ch=num[l].id-num[r].id;
        b=false;
       chh[1]=num[l].a;
       }else{
           ch=num[r].id-num[l].id;
           b=true;
       chh[1]=num[r].a;
       }
       if(num[l].a!=num[r].a){
           if(b){
            ans+=num[l].id;
           }else{
               ans+=num[r].id;
           }
       }
       l++;
       r--;
    }
    cout<<ans;
    return 0;
}
