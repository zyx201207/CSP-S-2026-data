#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int n,m,las,flag,a[maxn],f[maxn],l[maxn],num[maxn],ans[maxn];
vector<int>lo[maxn];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(f[a[i]]==0) f[a[i]]=i;
		lo[a[i]].push_back(i);
		l[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		if(i>1){
			las=a[i-1];
			num[las]++;
			f[las]=lo[las][num[las]];
		}
		for(int j=1;j<=m;j++){
			flag=1;
			if(l[j]<i) continue;
			for(int k=i;k<f[j];k++){
				if(l[a[k]]>l[j]){
					flag=0;
					break;
				}
			}
			if(flag){
				ans[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
