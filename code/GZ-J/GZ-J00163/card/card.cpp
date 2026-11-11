//GZ-J00163 遵义市汇川区第二小学 韩铭钊 
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],f,ans[300005],t[300005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]) f=0;
	}
	if(f==1){
		for(int i=1;i<=m;i++){
			cout<<upper_bound(a+1,a+n+1,i)-a-1<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		stack<int> s;
		memset(t,0,sizeof(t));
		for(int j=i;j<=n;j++){
			if(t[a[j]]){
				while(s.top()!=a[j]){
					t[s.top()]=0;
					s.pop();
				}
			}else{
				s.push(a[j]);
				t[a[j]]=1;
			}
		}
		for(int i=1;i<=m;i++){
			if(t[i]){
				ans[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
    return 0;
}

