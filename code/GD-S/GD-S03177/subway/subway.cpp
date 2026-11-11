#include <bits/stdc++.h>
using namespace std;
int w[2505];
vector<int> a[501];
int t[501][501];
int mapp[501][501];
int k;
int find(int l1,int l2){
	for(int i:a[l1]){
		for(int j:a[l2]){
			if(i==j)return j;
		}
	}
	return 8000168;
}
int f(int l,int x){
	int cnt=0;
	for(int i:a[l]){
		cnt++;
		if(i==x)return cnt;
	}
	return 8000168;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			int h;
			cin>>h;
			a[i].push_back(h);
			cin>>t[i][j];
		}
	}
	
	cout<<find(1,2)<<endl;
	
	for(int i=1;i<=500;i++){
		for(int j=1;j<=500;j++)mapp[i][j]=0x3f3f3f3f;
	}
	for(int i=1;i<=500;i++)mapp[i][i]=0;
	
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				int ij=find(i,j);
				if(ij!=8000168){
					int lij=t[i][f(i,ij)]+t[j][f(j,ij)];
					mapp[i][j]=min(mapp[i][j],lij);
					continue;
				}
				int ik=find(i,k),jk=find(j,k);
				if(ik!=8000168&&jk!=8000168){
					int lik=t[i][f(i,ik)]+t[k][f(k,ik)];
					int ljk=t[j][f(j,jk)]+t[k][f(k,jk)];
					mapp[i][j]=min(mapp[i][j],lik+ljk);
				}
			}
		}
	}
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			mapp[i][j]=mapp[i][j]+w[i]+w[j];
			//cout<<mapp[i][j]<<" ";
		}
		//cout<<endl;
	}
	
	while(q--){
		int l,r;
		cin>>l>>r;
		int minn=0x3f3f3f3f;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(f(i,l)!=8000168&&f(j,r)!=8000168)minn=min(minn,mapp[i][j]);
			}
		}
		
		if(minn%2==0)minn=minn*2+1;
		else minn=minn*2+2;
		cout<<minn<<"\n";
	}
	return 0;
}

