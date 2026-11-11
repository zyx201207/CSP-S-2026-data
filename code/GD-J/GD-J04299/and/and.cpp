#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+7;
int k[N]={},is[N]={};
bool use[N]={};
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,b;
	cin>>n>>b;
	for(int i=0;i<n;i++)cin>>k[i];
	int ans=0;
	memset(use,1,sizeof(use));
	for(int i=32;i>=0;i--){
		int c=0,cnt=0,val=pow(2,i);
		memset(is,0,sizeof(is));
		for(int l=0;l<n;l++){
			if(!use[l])continue;
			if(k[l]>=val){
				cnt++;
				k[l]-=val;
			}
			else is[c++]=l;
		}if(cnt>=b){
			ans+=val;
			for(int l=0;l<c;l++)use[is[l]]=0;
		}
	}cout<<ans;
	return 0;
}
