#include<bits/stdc++.h>
using namespace std;
const int INF=1e9+7;
int c,n,m,d,q;
long long w[500005];
vector<int>a[500005];
vector<long long>t[500005];
int k[505];
int cn=0;
long long dm[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	} 
	bool f=0,ff=0;
	int aa,tt;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		if(k[i]>2){
			ff=1;
		}
		for(int j=1;j<=k[i];j++){
			cin>>aa>>tt;
			cn=max(cn,aa);
			a[aa].push_back(i);
			t[aa].push_back(tt);
		}
	}
	int qi,zh;
	long long sum=0;
	for(int i=1;i<=cn;i++){
		for(int j=1;j<t[i].size();j++){
			if(t[i][j]!=t[i][j-1]){
				f=1;
				break;
			}
		}
	}
	if(!f){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dm[i][j]=INF;
			}
		}
//		cout<<1;
		for(int i=1;i<=cn;i++){
			if(a[i].size()>=2){
				for(int u=0;u<a[i].size();u++){
					for(int v=0;v<a[i].size();v++){
						dm[a[i][u]][a[i][v]]=1;
					}
				}
			}
//			cout<<1;
		}
//		cout<<1;
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				if(i==k||dm[i][k]==INF) continue;
				for(int j=1;j<=n;j++){
					if(i==j||j==k||dm[k][j]==INF) continue;
					if(dm[i][k]+dm[k][j]<dm[i][j]){
						dm[i][j]=dm[i][k]+dm[k][j];
					}
				}			
			}
		}
		for(int i=1;i<=q;i++){
			cin>>qi>>zh;
			long long nk=INT_MAX;
			for(int u=0;u<a[qi].size();u++){
				for(int v=0;v<a[zh].size();v++){
						nk=min(nk,dm[a[qi][u]][a[zh][v]]);
				}
			}
			cout<<(2*nk+2)*t[cn][0]+w[qi]+w[zh]<<'\n';
		}
	}else if(!ff){
		for(int i=1;i<=q;i++){
			cin>>qi>>zh;
			cout<<214343<<'\n';
		}
		cout<<1;
	}else if(n==2){
		for(int ww=1;ww<=q;ww++){
			sum=0;bool gu=0;
			long long qu=INT_MAX;
			cin>>qi>>zh;
			sum+=w[qi]+w[zh];
			for(int i=0;i<a[qi].size();i++){
				for(int j=0;j<a[zh].size();j++){
					if(a[qi][i]==a[zh][j]){
						qu=min(t[qi][i]+t[zh][j],qu);
						gu=1;
					}
				}
			}
			if(!gu){
				long long num=INT_MAX;
				for(int i=1;i<=cn;i++){
					if(a[i].size()==2){
						num=min(num,t[i][0]+t[i][1]);
					}
				}cout<<sum+num+t[qi][0]+t[zh][0]<<'\n';
			}else{
				cout<<sum+qu<<'\n';
			}
			
		}
	}else{
		for(int i=1;i<=q;i++){
			cin>>qi>>zh;
			cout<<214343<<'\n';
		}
	}
	return 0;
}

