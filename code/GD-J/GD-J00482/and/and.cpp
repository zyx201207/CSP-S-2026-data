#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct node{
	int cnt[35],v;
	bool vis;
}a[N];
int sum[35];
bool cmp(node x,node y){
	return x.v>y.v;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		a[i].v=x;
		int s=0; 
		while(x>0){
			a[i].cnt[s]=x&1;
			sum[s++]+=x&1;
			x/=2;
		}
	}
	sort(a,a+n,cmp);
	int s=n;
	for(int i=30;i>=0;i--){
		if(sum[i]==0||sum[i]<m)continue;
		if(s==m)break;
		for(int j=0;j<n;j++){
			if(s==m)break;
			if(a[j].vis){
				sum[i]-=a[j].cnt[i];
				continue;
			}
			if(a[j].cnt[i]==0){
				a[j].vis=1;
				s--;
			}
		}
	}
	int ans;
	for(int i=0;i<n;i++){
		if(!a[i].vis)ans=a[i].v;
	}
	for(int i=0;i<n&&s>=0;i++){
		if(!a[i].vis){
			ans=ans&a[i].v;
			s--;
		}
	}
	cout<<ans;
	return 0;
}
