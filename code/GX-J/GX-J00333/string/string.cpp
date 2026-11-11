#include<bits/stdc++.h>
using namespace std;

long long n,l=1,r,cnt;
struct stu{
    long long ai;
    char ch;
}a[200005];

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    r=n;
    for(int i=1;i<=n;i++){
        cin>>a[i].ai;
        cin>>a[i].ch;

    }
    while(l<r){
        if(a[l].ch==a[r].ch){
            if(a[l].ai<a[r].ai){
                a[r].ai-=a[l].ai;
                l++;
            }
            else if(a[l].ai==a[r].ai){
                l++;
                r--;
            }
            else{
                a[l].ai-=a[r].ai;
                r--;
            }
        }
        else{
            if(a[l].ai<a[r].ai){
                a[r].ai-=a[l].ai;
                cnt+=a[l].ai;
                l++;
            }
            else if(a[l].ai==a[r].ai){
                cnt+=a[l].ai;
                l++;
                r--;
            }
            else{
                a[l].ai-=a[r].ai;
                cnt+=a[r].ai;
                r--;
            }
        }
    }
    cout<<cnt;



    return 0;
}
