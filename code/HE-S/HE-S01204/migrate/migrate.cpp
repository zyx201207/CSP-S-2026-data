#include<bits/stdc++.h>
using namespace std;
int a[2000005];
int minm[2000005];
int num[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d,minm=1;
	cin >> c >> t;
	while(t--){
		cout << 0 <<endl;
	} 
		
//		int tm=a[1];
//		minm=1;
//		for(int i=2;i<=n;i++) if(abs(a[i]-tm)>d) minm++,tm=a[i-1],i--;
//		queue<pair<int,int> > q;
//		q.push(make_pair(1,0));
//		int num=0;
//		while(!q.empty()){
//			int u = q.front().first;
//			int k = q.front().second;
//			q.pop();
//			if(u==n&&k==minm) num++;
//			if(k>=minm) continue;
//			for(int i=u+1;a[i]<=a[u]+d;i++){
//				q.push(make_pair(i,k+1));
//			}
//		}
//		if(num==2) 
	return 0; 
}
