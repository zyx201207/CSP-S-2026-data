#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;cin>>n>>m;
	vector<long long>a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	vector<long long>ans(m+1,0);
	vector<long long>p(n,0);
	for(int i=1;i<=n;i++){
		for(int j=0;j<n;j++)p[j]=0;
		int las=0;
		for(int j=i;j<=n;j++){
			int pi=a[j];
			bool flag=0;
			
			for(int k=0;k<n;k++){
				if(flag&&p[k]!=0){
					p[k]=0;
					las--;
				}else if(p[k]==pi){
					flag=1;
					p[k]=0;
					las--;
				}
			}
			
			p[las]=pi;
			las++;
		}
		for(int j=0;j<n;j++){
			if(p[j]!=0)ans[p[j]]++;
		}
	}
	for(int i=1;i<m+1;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
