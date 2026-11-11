#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,a,b,s=0;
int arr[10000000];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--){
        scanf("%d%d",&n,&k);
        for(int i=1;i<n;i++){
            scanf("%d%d",&a,&b);
            if(a==k||b==k)
                s++,arr[s]=b-a;
        }
        sort(arr+1,arr+s+1);
        cout<<arr[1];
        s=0;
    }
    return 0;
}
