#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],ans[300005],flag[300005],wz[300005];
stack<int> q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	long long nn=n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	while(nn>=0){
		long long nt=1;
		for(long long i=n-nn;i<=n;i++){
			if(flag[a[i]]==0){
				q.push(a[i]);
				b[nt]=a[i];
				wz[a[i]]=nt;
				nt++;
				flag[a[i]]=1;
			}
			else{
				nt--;
				while(!q.empty()){
					if(nt==wz[a[i]]){
						q.pop();
						break;
					}
					flag[b[nt]]=0;
					q.pop();
					nt--;
				}
				q.push(a[i]);
				wz[a[i]]=nt;
			}
		}
		for(int i=1;i<=n;i++){
			if(flag[a[i]]==1) {
				flag[a[i]]=0;
				ans[a[i]]++;
			}
		}
		nn--;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[a[i]]<<' ';
	}
	return 0;
}
