#include <bits/stdc++.h>
using namespace std;
int n,ans;
struct node{
    int cnt;
    char zi;
};
node a[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d %c",&a[i].cnt,&a[i].zi);
    }
    for(long long i=1,j=n;i<j;){
        if(a[i].zi==a[j].zi){
            if(a[i].cnt==a[j].cnt){
                i++,j--;
                continue;
            }
            if(a[i].cnt>a[j].cnt){
                a[i].cnt-=a[j].cnt;
                j--;
                continue;
            }if(a[j].cnt>a[i].cnt){
                a[j].cnt-=a[i].cnt;
                i++;
                continue;
            }
        }if(a[i].zi!=a[j].zi){
            if(a[i].cnt>a[j].cnt){
                ans+=a[j].cnt;
                a[i].cnt-=a[j].cnt;
                j--;
                continue;
            }if(a[j].cnt>a[i].cnt){
                ans+=a[i].cnt;
                a[j].cnt-=a[i].cnt;
                i++;
                continue;
            }if(a[j].cnt==a[i].cnt){
                ans+=a[i].cnt;
                i++,j--;
                continue;
            }
        }
    }cout<<ans;
    return 0;
}