#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],b[35][200005],k[50];
queue<int>p;
queue<int>pp;
queue<int>q;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		int cnt=30;
		while(a[i]!=0){
			b[i][cnt]=a[i]%2;
			a[i]/=2;
			cnt--;
		}
	}
	long long ans=0;
	k[1]=1;
	for(int i=2;i<=30;i++) k[i]=k[i-1]*2;
	for(int i=1;i<=n;i++) p.push(i);
	for(int i=1;i<=30;i++){
		int num=0;
		while(!p.empty()){
			int j=p.front();
			p.pop();
			pp.push(j);
			if(b[j][i]==1){
				q.push(j);
				num++;
			}
		}
		if(num<m){
			while(!pp.empty()){
				p.push(pp.front());
				pp.pop();
			}
			while(!q.empty()) q.pop();
			continue;
		}
		while(!pp.empty()) pp.pop();
		ans+=k[30-i+1];
		while(!q.empty()){
			p.push(q.front());
			q.pop();
		}
	}
	cout<<ans;
	return 0;
}
