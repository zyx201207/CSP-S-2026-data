#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,NLOG2=40; 
struct node{
	int w;
	bool w_2[NLOG2];
}a[N];
int n,m,sumw[N],vis[N];
bool cmp(node x,node y){
	return x.w>y.w;
}
vector<int> sum[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) for(int j=1;j<=NLOG2;j++) a[i].w_2[j]=false;
	for(int i=1;i<=n;i++) cin>>a[i].w;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		int w=a[i].w;
		for(int j=30;j>=0;j--){
			if(w>=pow(2,j)) w-=pow(2,j),a[i].w_2[j]=true,sum[j].push_back(i);
		}
	}
	long long ans=0;
	for(int i=30;i>=0;i--){
		if(sum[i].size()>=m){
			ans+=pow(2,i);
			int cnt,p;
			for(int j=0;j<sum[i].size();j++) vis[sum[i][j]]=1;
			for(int j=i-1;j>=0;j--){
				cnt=0;p=0;
				for(int k=0;k<sum[j].size();k++){
					if(vis[sum[j][k]]>0) p=vis[sum[j][k]],cnt++,vis[sum[j][k]]++;
				}
				if(cnt>=m){
					ans+=pow(2,j);
					for(int k=0;k<sum[i].size();k++){
						if(vis[sum[i][k]]==p) vis[sum[i][k]]=0;
					}
				}
			}
			break;
		}
	}
	cout<<ans;
	return 0;
}
