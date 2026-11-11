#include<bits/stdc++.h>
using namespace std;
int n,m; 
queue<long long>q;
long long a[500005],s[500005],tmp,cnt;
int ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",a+i);
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
    	s[i]=a[i]-a[i-1];
	}
    for(int i=2;i<=n;i++){
        q.push(s[i]);
        tmp+=s[i];
        cnt+=q.size()*s[i];
        while(cnt>m){
            cnt-=tmp;
            tmp-=q.front();
            q.pop();
        }
        if(ans<q.size()+1) ans=q.size()+1;
    }
    printf("%d",ans);
    return 0;
}
