#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n,m;
int a[maxn];
int b[32];
vector<int>G[32];
long long ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int tmp=a[i];
		int cnt=0;
		while(tmp){
//			cout<<cnt<<" "<<tmp<<" "<<(tmp&1)<<"\n";
			if(tmp&1){
				b[cnt]++;
				G[cnt].push_back(i);
			}
			tmp>>=1;
			cnt++; 
		}
	}
	int last=31;
	while(1){
		int wei=-1;
		for(int i=last;i>=0;i--){
//			cout<<"i="<<i<<" b[i]="<<b[i]<<"\n";
			if(b[i]>=m){
				wei=i;
				break;
			}
		}
		if(wei==-1){
			cout<<ans;
			return 0;
		}
		ans+=(1<<wei);
		last=wei-1;
		memset(b,0,sizeof(b));
		for(int i=wei-1;i>=0;i--)G[i].clear();
		for(int i=0;i<G[wei].size();i++){
			int tmp=a[G[wei][i]];
			int cnt=0;
			while(tmp&&cnt<wei){
//				cout<<cnt<<" "<<tmp<<" "<<(tmp&1)<<"\n";
				if((tmp&1)&&cnt!=wei){
					b[cnt]++;
					G[cnt].push_back(G[wei][i]);
				}
//				cout<<b[cnt]<<"\n";
				tmp>>=1;
				cnt++; 
			}
		}
	}
} 
