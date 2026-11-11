#include<bits/stdc++.h>
using namespace std;
const int  N=100005;
vector<int> e[N];
int main(){
	freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,k;
        scanf("%d %d",&n,&k);
        for(int i=1;i<n;i++){
            int u,v;
            scanf("%d %d",&u,&v);
            e[u].push_back(v);
            e[v].push_back(u);
        }
        int m=n/2;
        if(m%2==1){
            m=(m+1)/2;
        }
        else{
            m=m/2;
        }
        if(k%2==1){
            k=(k-1)/2;
        }
        else{
            k=k/2;
        }
        if(m%2!=k%2){
            m++;
        }
        int ans=(m/2)-(k/2)+1;
        printf("%d\n",ans);
    }
    return 0;
}
