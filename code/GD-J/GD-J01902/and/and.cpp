#include <bits/stdc++.h>
#define int long long
using namespace std;
queue<int> que;
vector<int> vec[35];
int n,m,k,l,cnt,ans,minn=31,er[35],a[200020];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>l;
		que.push(l);
	}
	while(que.size()>=m){
		cnt=-1;
		n=que.size(); 
		for(int i=0;i<n;i++){
			a[i]=que.front();
			que.pop();
			l=a[i];k=0;
			while(l!=0 and k<minn){
				if(l%2==1)
					vec[k].push_back(a[i]);
				l=l/2;
				if(vec[k].size()>=m)
					cnt=max((int)cnt,(int)k);
				k++;
			}
		}
		if(cnt==-1)
			break;
		minn=cnt;
		er[cnt]=1;
		while(!que.empty())
			que.pop();
		for(auto i:vec[cnt])
			que.push(i);
		for(int i=0;i<=30;i++)
			vec[i].clear();
	}
	for(int i=0;i<=30;i++)
		ans=ans+(er[i]<<i);
	cout<<ans;
	return 0;
}
