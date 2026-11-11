#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long b[300005];
long long c[300005];
int n,m;
vector<long long>q;
int fd(long long k){
	for(int i=k;i<=n;i++){
		if(b[a[i]]==0){
			q.push_back(a[i]);
			b[a[i]]=1;
		}
		else {
			long long h;
			for(int i=0;i<q.size();i++){
				long long w1=q[i];
				if(w1==a[i]){
					h=i;
				}
			}
			long long k=q.size();
			for(int i=h;i<k;i++){
				q.erase(q.begin()+i);
			}
			q.push_back(a[i]);
		}
	}
	while(!q.empty()){
		long long w=q.back();
		c[w]++;
		q.pop_back();
	}
	return 0;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	for(int i=1;i<=n;i++){
		q.clear();
		memset(b,0,sizeof(b));
		fd(i);
	} 
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
