#include<bits/stdc++.h>
using namespace std;
int cnt[5005],lpos,h[5005],dis[5005];
long long x[5005];
void f(int s){
	queue<int>q;
	q.push(s);
	while(!q.empty()){
		int t = q.front();
		q.pop();
		//cout<<t<<" ";
		for(int i = h[t]; i < t; i++){
			if(dis[i] == -1||(dis[i]!=-1&&dis[i]>=dis[t]+1)){
				if(dis[i] > dis[t] + 1&& dis[i] != -1){
					cnt[i] = 0;
				}
				dis[i] = dis[t] + 1;
				q.push(i);
				cnt[i]++;
				lpos = min(i,lpos);
			}
		}
	}
	//cout<<endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		int n,l=1;
		long long d,ans = 0;
		cin>>n>>d;
		lpos = n;
		for(int i = 1; i <= n; i++){
			cin>>x[i];
			while(l < i && x[i] - x[l] > d) l++;
			h[i] = l;
			//cout<<h[i]<<" ";
		}
		for(int i = n; i >= 1; i--){
			for(int j = 1; j <= i; j++){
				dis[j] = -1;
				cnt[j] = 0;
			}
			f(i);
			//cout<<"lpos"<<lpos<<"i"<<i<<endl;
			for(int j = lpos; j < i; j++){
				//cout<<cnt[j]<<" ";
				if(cnt[j] == 2) ans++;
			}
			//cout<<"/"<<endl<<ans<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}
