#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int a[N],n,m,ans[N];
struct node{
    int a,pos;
}t[N];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
            if(t[a[j]].a==0){
                t[a[j]].a++;
                t[a[j]].pos=j;
            }else{
                for(int i=t[a[j]].pos;i<=n;i++){
                    t[a[j]].pos=0;
                    t[a[j]].a=0;
                }
                t[a[j]].a++;
                t[a[j]].pos=j;
            }
		}
		for(int j=1;j<=m;j++){
            ans[j]+=t[j].a;
		}
	}
	for(int j=1;j<=m;j++){
        cout<<ans[j];
    }
    return 0;
}

