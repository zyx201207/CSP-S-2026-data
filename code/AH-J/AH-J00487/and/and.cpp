#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    int a,b,maxn=-1;
    cin>>a>>b;
    int ans[100005];
    for(int i=1;i<=a;i++){
		cin>>ans[i];
		maxn=max(maxn,ans[i]);
    }
    if(b==1)return cout<<maxn,0;
    sort(ans+1,ans+a+1);
    cout<<ans[b];
	return 0;
}
