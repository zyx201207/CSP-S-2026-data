#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005];
int n,m;
bool f[200005][35];
vector<int>k;
vector<int>next;
vector<int>q[35];
int ks(int x){//2的次方数 
	int w=-1;
	while(x){
		x>>=1;
		w++;
	}
	return w;
}
void fj(int x,int h){
	while(x){
		int ls=x&(x-1);
		int l1=x-ls;
		int dk=ks(l1);
		f[h][dk]=1;
		q[dk].push_back(h);
		x=ls;
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int maxn=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		fj(a[i],i);
		maxn=max(maxn,ks(a[i]));
	}
	int ans=0;
	bool t=1;
	for(int i=maxn;i>=0;i--){
		if((q[i].size()<m)&&(t))continue;//num:存在第i位的数量 
		if(t){
			for(int j=0;j<q[i].size();j++){
				k.push_back(q[i][j]);
			}
			ans+=(1<<i);
			t=0;
			continue;
		}else{
			int s=0;
			next.clear();
			for(int j=0;j<k.size();j++){
				if(f[k[j]][i]){//k：可能备选数组 
					s++;//f：数组中第j个值是否有第i个1 
					next.push_back(k[j]);
				}
			}
			if(s>=m){
				ans+=(1<<i);
				swap(next,k);
			}
		}
	}
	cout<<ans;
	return 0;
} 
