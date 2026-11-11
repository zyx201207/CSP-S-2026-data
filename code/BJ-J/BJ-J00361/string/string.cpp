#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct str{
    long long a;
    char b;
}arr01[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,cnt=0; cin>>n;
    for(int i=0;i<n;++i)
        cin>>arr01[i].a>>arr01[i].b;
    for(int i=0,j=n-1;i<j;++i,--j){
        if(arr01[i].a==arr01[j].a){
            if(arr01[i].b==arr01[j].b)
                continue;
            if(arr01[i].b!=arr01[j].b){
                cnt+=arr01[i].a;
                arr01[i].b=arr01[j].b;
            }
        }
        if(arr01[i].a!=arr01[j].a){
            if(arr01[i].b==arr01[j].b){
                if(i==j-1)
                    continue;
                if(arr01[i].a>arr01[j].a){
                    cnt+=(arr01[i].a-arr01[j].a);
                    arr01[i+1].a+=(arr01[i].a-arr01[j].a);
                }
                if(arr01[i].a<arr01[j].a){
                    cnt+=(arr01[j].a-arr01[i].a);
                    arr01[j-1].a+=(arr01[j].a-arr01[i].a);
                }
            }
            if(arr01[i].b!=arr01[j].b){
                if(arr01[i].a>arr01[j].a){
                    cnt+=arr01[i].a;
                    arr01[i+1].a+=(arr01[i].a-arr01[j].a);
                }
                if(arr01[i].a<arr01[j].a){
                    cnt+=arr01[j].a;
                    arr01[j-1].a+=(arr01[j].a-arr01[i].a);
                }
            }
        }
    }
    cout<<cnt<<'\n';
    return 0;
}
