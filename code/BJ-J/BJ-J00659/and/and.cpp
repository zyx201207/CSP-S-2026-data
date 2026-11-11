#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans,f[25];
void dfs(int step,int cnt) {
    if(step>n) {
        if(cnt!=m) return;
        int sum;
        for(int i=1;i<=n;i++) if(f[i]==1) {sum=a[i];break;}
        for(int i=1;i<=n;i++) if(f[i]==1) sum&=a[i];
        ans=max(ans,sum);
        return;
    } 
    if(cnt==m) {
        f[step]=0;
        dfs(step+1,cnt);
    }
    else {
        f[step]=1;
        dfs(step+1,cnt+1);
        f[step]=0;
        dfs(step+1,cnt);
    }
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    sort(a+1,a+n+1,greater<int>());
    if(n<=20) {
        dfs(1,0);
        cout<<ans;
    }
    else if(m==1) {
		cout<<a[1];
	}
	else if(m==2) {
		for(int i=1;i<=n;i++) {
			for(int j=i+1;j<=n;j++) {
				ans=max(ans,a[j]&a[i]);
			}
		}
		cout<<ans;
	}
	else if(m==n) {
		ans=a[1];
		for(int i=1;i<=n;i++) {
			ans&=a[i];
		}
		cout<<ans;
	}
	else {
		ans=a[1];
		for(int i=2;i<=m;i++) {
			ans&=a[i];
		}
		cout<<ans;
	}
    return 0;
}
