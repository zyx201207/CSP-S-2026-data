#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010];
long long js[500010];
long long js1[500010];
queue<long long>q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(long long i=1;i<=n;i++){
		cin >> a[i];
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
			if(js[a[j]]!=0){
				q.push(0);
				while(q.front()!=a[j]){
					q.push(q.front());
					q.pop();
				}
				while(q.front()!=0){
					long long z=q.front();
					js[z]--;
					q.pop();
				}
				q.pop();
			}
			q.push(a[j]);
			js[a[j]]++;
		}
		q.push(0);
		while(q.front()!=0){
			long long z=q.front();
			js1[z]++;
			js[z]=0;
			q.pop();
		}
		q.pop();
	}
	for(long long i=1;i<=m;i++){
		cout << js1[i] << " ";
	}
	return 0;
} 
