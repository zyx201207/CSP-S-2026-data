#include<bits/stdc++.h>

using namespace std;

const int L=31,N=2e5+10;//max=2^30
int n,m;
int p=1;
int f[L*N][2];//i->0f[i][0],i->1f[i][1]
int tree[L*N],cnt[L*N];
void build(int a){
	int j=0;
	for(int i=30;i>=0;i--){
		int c=a>>i;
		a-=c<<i;
		if(f[j][c]==0){
			f[j][c]=p;
			tree[p]=c;
			cnt[p++]++;
			j=p;
		}
		else{
			j=f[j][c];
			cnt[j]++;
		}
	}
}
int query(){
	int j=0,ans=0;
	for(int i=30;i>=0;i--){
		if(f[j][1]!=0 && cnt[f[j][1]]>=m){
			ans+=1<<i;
			j=f[j][1];
		}
		else if(f[j][0]!=0 && cnt[f[j][0]]>=m){
			j=f[j][0];
		}
		else{
			return ans;
		}
	}
	return ans;
}

int main(){//01xian duan shu
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		build(a);
	}
	cout<<query();
	return 0;
	
}
