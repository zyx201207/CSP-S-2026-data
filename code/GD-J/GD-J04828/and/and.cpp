#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans,a[200005],q2[35];
vector<long long>b[32],w;
priority_queue<long long>q;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	q2[0]=1;
	for(int i=1;i<=31;i++){
		q2[i]=q2[i-1]<<1;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int x=0;
		long long a2=a[i];
		while(a2>0)a2/=2,x++;
		b[x].push_back(a[i]);
	}
	long long cnt=0,ci=0;
	for(int i=31;i>=1;i--){
		cnt+=b[i].size();
		if(cnt>=m){
			ci=i;
			break;
		}
	}
	long long cnt2=0;
	for(int i=31;i>=ci;i--){
		if(b[i].size()==0)continue;
		for(auto j:b[i]){
			long long qq=j;
			for(int k=i;k>=ci;k--){
				if(q2[k]<=qq)qq-=q2[k];
			}
			if(qq>=q2[ci-1])cnt2++;
			w.push_back(qq);
		}
	}
	long long ci2=ci,cnt3=cnt2;
	while(cnt2<m){
		ci--;
		cnt3+=b[ci].size();
		if(cnt3>m){
			for(int i=0;i<w.size();i++){
				for(int k=ci2-1;k>=ci;k--){
					if(q2[k]<=w[i])w[i]-=q2[k];
				}
			}
			for(int i=ci2-1;i>=ci;i--){
				if(b[i].size()==0)continue;
				for(auto j:b[i]){
					long long qq=j;
					for(int k=i;k>=ci;k--){
						if(q2[k]<=qq)qq-=q2[k];
					}
					if(qq>=q2[ci-1])cnt2++;
					w.push_back(qq);
					ci2=ci;
				}
			}
		}
	}
	for(int i=0;i<w.size();i++)q.push(w[i]);
	for(int i=1;i<=m;i++){
		if(i==1)ans=q.top();
		else ans&=q.top();
		q.pop();
	}
	cout<<ans;
	return 0;
}
