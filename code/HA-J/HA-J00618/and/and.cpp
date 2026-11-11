#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int ans=INT_MAX,a[N],n,m;
struct node{
	int val,pos;
}tmp[N];
bool cmp(node x,node y){
	return x.val>y.val;
}
vector<int> tot[33];
bool tot2[33][N],dis[N];
void fun(int x,int f){
	int nx=x,cntt=0;
	while(nx){
		if(nx&1){
			tot[cntt].push_back(f);
			tot2[cntt][f]=1;
		}
		nx>>=1;
		++cntt;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m; 
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		tmp[i].pos=i,tmp[i].val=a[i];
		fun(a[i],i);
	}
	for(int i = 31; i >= 0; i--){
		int cnt = 0;
		for(int j = 1; j <= n; j++){
			cnt += (!dis[j]&&tot2[i][j]);
		}
		if(cnt<m){
			for(int jj = 0; jj < tot[i].size(); jj++){
				int j=tot[i][jj];
				tmp[j].val=tmp[j].val-(1<<i);
			}
		}else{
			for(int j = 1; j <= n; j++)dis[j]=max(dis[j],!tot2[i][j]);
		}
	}
	sort(tmp+1,tmp+1+n,cmp);
	for(int i = 1; i <= m; i++){
		int k = tmp[i].pos; 
		ans = ans & a[k];
//		cout << (49&55) << '\n';
	}
	cout << ans;
	return 0;
}


