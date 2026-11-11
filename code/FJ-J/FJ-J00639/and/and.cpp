#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],ans;
queue<int> q;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
//	sort(a+1,a+n+1,greater<int>());
//	for(int i=1;i<=n;i++){
//		for(int j=5;j>=0;j--){
//			if(a[i]&(1<<j)) cout<<1;
//			else cout<<0;
//		}
//		cout<<endl;
//	}
	for(int j=30;j>=0;j--){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]&(1<<j)) cnt++;
		}
		if(cnt<m) continue;
		queue<int> q;
		for(int i=1;i<=n;i++){
			if((a[i]&(1<<j))) q.push(a[i]);
		}
		int now=0;
		while(q.size()){
			a[++now]=q.front();
			q.pop();
		}
		n=now;
//		printf("%d ",j);
//		for(int i=1;i<=n;i++) printf("%d ",a[i]);
//		printf("\n");
		ans+=(1<<j);
	}
	printf("%d",ans);
	return 0;
}
/*
7 2
45 55 53 28 57 24 6 
*/
