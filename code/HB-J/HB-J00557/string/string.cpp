#include<bits/stdc++.h>
using namespace std;
struct node{
    int num;
    string s;
};
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    string s="";
    cin>>n;
    node a[n+1];
    long long ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i].num>>a[i].s;
        ans+=a[i].num;
        for(int j=1;j<=a[i].num;j++){
            s+=a[i].s;
        }
    }
    int cnt=0;
    if(ans%2!=0){
        for(int i=0;i<=ans/2-1;i++){
            if(s[i]!=s[ans-1-i]){
                cnt++;
            }
        }
    }
    else{
        for(int i=0;i<=ans/2;i++){
            if(s[i]!=s[ans-1-i]){
                cnt++;
            }
        }
    }
    cout<<cnt;
    return 0;
}
/*#include<bits/stdc++.h>
using namespace std;
struct node{
    int num;
    string s;
};
int main(){
    freopen("string4.in","r",stdin);
    freopen("string4.out","w",stdout);
    int n;
    cin>>n;
    node a[n+1];
    long long ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i].num>>a[i].s;
        ans+=a[i].num;
    }
    int cnt=0,x=0,c;
    if(ans%2!=0){
        for(int i=1;i<=n;i++){
            c+=a[i].num;
            if(c>=ans/2){
                x=i;
                break;
            }
        }
        c=0;
        for(int i=0;i<x;i++){
            if(a[i].s!=a[n-1-i].s){
                cnt+=max(a[i].num+c,a[n-1-i].num);
            }
            c=a[i].num+c-a[n-1-i].num;
        }
        cout<<cnt;
    }
    else{
        for(int i=1;i<=n;i++){
            c+=a[i].num;
            if(c>=ans/2){
                x=i;
                break;
            }
        }
        c=0;
        for(int i=0;i<x;i++){
            if(a[i].s!=a[n-1-i].s){
                cnt+=max(a[i].num+c,a[n-1-i].num);
            }
            c=a[i].num+c-a[n-1-i].num;
        }
        cout<<cnt;
    }
    return 0;
}*/
