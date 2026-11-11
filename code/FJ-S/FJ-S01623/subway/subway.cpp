#include<bits/stdc++.h>
using namespace std;
struct Station{
	long long id;
    long long Towards[505];
};
Station ss[505];
long long Floyd[505][505];
long long More[505]; 
vector<long long> Twrd;
vector<long long> Cost;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	if(m<500){
	    for(int i=1;i<=m;i++){
			cin>>More[i];
		}
		for(int i=0;i<505;i++){
			for(int j=0;j<505;j++){
				ss[i].Towards[j]=0x3f3f3f3f3f3f3f3f;
				Floyd[i][j]=0x3f3f3f3f3f3f3f3f;
			}
		}
		for(int i=1;i<=n;i++){
			long long k;
			cin>>k;
			Twrd.clear();
			Cost.clear();
			for(int j=1;j<=k;j++){
	            long long tw,ct;
	            cin>>tw>>ct;
				for(int k=0;k<Twrd.size();k++){
				    ss[tw].Towards[Twrd[k]]=min(ss[tw].Towards[Twrd[k]],ct+Cost[k]);
				    ss[Twrd[k]].Towards[tw]=ss[tw].Towards[Twrd[k]];
				}
				Twrd.push_back(tw);
				Cost.push_back(ct);
			}
		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(ss[i].Towards[j]!=0x3f3f3f3f3f3f3f3f){
					Floyd[i][j]=ss[i].Towards[j];
				}
			}
		}
		for(int k=1;k<=m;k++){
			for(int j=1;j<=m;j++){
				for(int i=1;i<=m;i++){
					if((i!=j && j!=k) && i!=k){
						Floyd[i][j]=min(Floyd[i][j],Floyd[i][k]+Floyd[j][k]);
						Floyd[j][i]=Floyd[i][j];
					}
				}
			}
		}
		for(int i=1;i<=q;i++){
			long long a,b;
			cin>>a>>b;
			cout<<Floyd[a][b]+More[a]+More[b]<<'\n';
		}
	}
	else {
		cout<<0;
	}
	return 0;
}
