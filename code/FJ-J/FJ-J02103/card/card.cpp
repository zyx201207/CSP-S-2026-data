#include<bits/stdc++.h>
using namespace std;
int p[300005][2];
int sum[500005];
queue<string> q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[500005];
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(p[a[j]-1][0]==0){
				p[a[j]-1][0]=1;
				p[a[j]-1][1]=j;
				q.front(a[j]);
			}else{
				for(int x=p[a[j]-1];x<n;x++) q.pop();
				p[a[j]-1][1]=j;
			}
		}
		for(int j=0;j<m;j++){
			sum[j]+=p[j][0];
		}
	}
	for(int i=0;i<n;i++) cout<<sum[i]<<' ';
	return 0;
}
