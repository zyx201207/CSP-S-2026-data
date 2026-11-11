#include<bits/stdc++.h>
using namespace std;
int c;
long long n,m,d,q;
long long k;
long long tc;
long long lt,tt;
long long vis_[500001]={0};
long long f[1010][1010];
long long a[500001][21]={0};
long long b[500001]={0};
long long cc[501][10010]={0};
long long dd[501]={0};
long long vit[501]={0};
long long t[10010][501];
long long p[5000010]={0};
void dfs(){
	int top=0,back=0;
	for(int i=1;i<=m;i++){
		for(int i=0;i<=1009;i++){
			for(int j=0;j<=1009;j++){
				f[i][j]=1000000001;
			}
		}
		for(int j=0;j<=500;j++){
			vit[i]=0;
		}
		p[top]=i;
		back++;
		int goal_=i;
		f[i][i]=0;
		while(top<=back){
			int goal=p[top];
			top++;
			for(int j=0;j<b[goal];j++){
				if(vit[a[goal][j]]==0){
					vit[a[goal][j]]=1;
					for(int kk=0;kk<dd[a[goal][j]];kk++){
						p[back]=cc[a[goal][j]][kk];
						back++;
						f[goal][cc[a[goal][j]][kk]]=min(f[goal][cc[a[goal][j]][kk]],f[goal_][goal]+t[cc[a[goal][j]][kk]][a[goal][j]]);
					}
				}
			}
			goal_=goal;
		}
	}
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		cin>>k;
		dd[i]=k;
		for(int j=0;j<k;j++){
			cin>>lt>>tt;
			t[lt][i]=tt;
			a[lt][b[lt]]=i;
			b[lt]++;
			cc[i][j]=lt;
		}
	}
	dfs();
	for(int i=0;i<q;i++){
		cin>>lt>>tt;
		cout<<f[lt][tt]<<endl;
	}
	return 0;
}
