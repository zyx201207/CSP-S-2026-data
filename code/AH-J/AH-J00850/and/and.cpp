#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],b[200005];
long long ans=-1,q[200005];
int cmp(int k1,int k2){
	return k1<k2;
}
bool ac(int aaa){
	if(aaa>=ans) ans=aaa;
}
void bfs(int step,int start){
	if(step>m){
		long long qwq=q[1];
		for(int j=2;j<=m;j++)  qwq=qwq&q[j];
		ac(qwq);
		return ;
	}
	for(int i=start;i<=n-(m-step);i++){
		if(b[i]==0){
			q[step]=a[i];
			b[i]=1;
		    bfs(step+1,start+1);
		    b[i]=0;
		}
		
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	sort(a+1,a+1+n,cmp);
	memset(b,0,sizeof(b));
	bfs(1,1);
	cout<<ans;
	return 0;
}


