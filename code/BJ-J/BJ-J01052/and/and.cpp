#include<bits/stdc++.h>
using namespace std;

const int MXN = 2e5+3 , MXD = 30 ;

int n,m,res;
bool a[MXN][MXD];
vector<int> v[2];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	int ta;
	for(int i=1;i<=n;i++){
		cin>>ta;
		for(int j=0;j<MXD;j++)
			if(ta&(1<<j))
				a[i][j]=1;
		v[0].push_back(i);
	}
	int o=0;
	for(int i=MXD-1;i>=0;i--){
		int cnt=0;
		for(int j:v[o])
			if(a[j][i])
				cnt++;
		if(cnt>=m){
			v[o^1].clear();
			for(int j:v[o])
				if(a[j][i])
					v[o^1].push_back(j);
			o^=1;
			res+=1<<i;
		}
	}
	cout<<res<<"\n";
	return 0;
}