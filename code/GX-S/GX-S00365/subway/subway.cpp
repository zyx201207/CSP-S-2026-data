#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[1000000],k,a[1000000],t[1000000],way,M[10000][10000],S,E;
long long ans;
bool U[1000000];
long long D(int st){
	long long an=0,mi=1000000;
	U[st]=true;
	for(int i=0;i<m;i++){
		if(M[st][i]!=-1&&!U[i]){
			if(i==E){
				an+=mi<M[st][i]?mi:M[st][i];
			}else{
				an+=min(mi,D(i));
			}
		}
	}
	U[st]=false;
	return an;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(M,-1,sizeof(M));
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		cin>>k;
		for(int j=0;j<k;k++){
			cin>>a[j]>>t[j];
			for(int l=0;l<j;l++){
				way=t[j]+t[l];
				if(M[j][l]==-1||way<M[j][l]){
					M[j][l]=way;
					M[l][j]=way;
				}
			}
		}
	}
	for(int i=0;i<q;i++){
		cin>>S>>E;
		ans=D(S)+w[S]+w[E];
		cout<<ans<<endl;
	}
	return 0;
}
