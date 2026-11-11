#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
	ios::sync_with_stdio(),cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	vector<int>time(m+1);
	int ways[m][n][n];
	for(int i=1;i<=m;i++){
		cin>>time[i];
	}
	for(int i=1;i<=n;i++){
		int s;cin>>s;
		for(int j=1;j<=s;j++)
		{
			int z;cin>>z;			
			cin>>ways[z][i][i];
	}
}
	for(int i=1;i<=q;i++){
		int sum=0;
		int b,e;
		cin>>b>>e;
		for(int j=b;j<=e;j++){
			for(int z=1;z<=n;z++){
					sum+=ways[j][z][z];	
					break;			
			}
				
		}
		sum+=(time[b]+time[e]);
		cout<<sum<<"\n";
	}


	return 0;
}



