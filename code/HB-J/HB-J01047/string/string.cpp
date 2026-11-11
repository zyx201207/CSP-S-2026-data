#include<bits/stdc++.h>
using namespace std;
bool k[200010];
char s[10000000];
struct stu{
    int num;
    char zhong;
}a[200010];
int main(){
   freopen("string.in","r",stdin);
   freopen("string.out","w",stdout);
    int n,x,x2,ans;
    char y,y2;
    cin>>n;
    if(n==1){
        cin>>x>>y;
        cout<<0;
        return 0;
    }else if(n==2){
        cin>>x>>y>>x2>>y2;
        if(y==y2) cout<<0;
        else cout<<min(x,x2);
        return 0;
    }else{
        int j=1;
        for(int i=1;i<=n;i++){
            cin>>a[i].num>>a[i].zhong;
            for(int k=j,l=1;l<=a[i].num;l++,k++){
                s[k]=a[i].zhong;
            }
            j+=a[i].num;
        }
        j--;
        for(int i=j,r=1;i>=1,r<=j;i--,r++){
            if(s[i]!=s[r]){
                s[r]=s[i];
                ans++;
            }
        }
        cout<<ans;
    }
    return 0;
}
