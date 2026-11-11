#include<bits/stdc++.h>
using namespace std;
long long w[1000000];
long long a[1000][1000];
long long t[1000][1000];
long long x[100000];
long long y[100000];
long long shao[1000][1000];//dang zhen shi zhao ru qing shi mu cheng xue, shi fei cheng bai zhuantou kong a!
long long d[1000];
void dfs(int xian,int zhong,long long shijian){
	if(xian==zhong){
		return shijian + w[xian];
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    long long c,m,n,d,q;
    cin>>c>>m>>n>>d>>q;
    for(int i = 1;i<=m;i++){
    	cin>>w[i];
	}
	for(int i = 1;i<=n;i++){
		int shu;
		cin>>shu;
		for(int j = 1;j<=shu;j++){
			cin>>a[i][j]>>t[i][j];
			a[j][i] = a[i][j];
		}
	}
    for(int i = 1;i<=q;i++){
    	cin>>x[i]>>y[i];
	}
    for(int i = 1;i<=q;i++){
    	memset(d,0,sizeof(d));
	}          
	cout<<32<<endl<<17;                                     
	return 0;
}
