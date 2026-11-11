#include<bits/stdc++.h>
using namespace std;
int a[500010],n,m,maxn=0,f,cnt,m1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n>>m;
    m1=m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    bool p=1;
    for(int i=1;i<=n;i++){
		if(a[i]!=a[i-1]){
			p=0;
		}
	}
	if(p==1){
		cout<<n;
		return 0;
	}
    sort(a+1,a+1+n);
    for(int i=n;i>=1;i--){
        f=i-1;
        m=m1;
        cnt=1;
        while(m>=0&&f>=0){
			if(a[i]==a[f]){
				cnt++;
				f--;
			}
            if(a[i]-a[f]<=m){
                cnt++;
                m-=a[i]-a[f];
                f--;
            }else{
                m=-1;
            }
            if(f==0){
                m=-1;
            }
        }
        maxn=max(cnt,maxn);
    }
    cout<<maxn;
    return 0;
}
