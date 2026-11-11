#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],pos[300005],c[500005],dcnt;
bool f=1;
struct node{
	int l,r;
}d[500005];
bool operator<(const node &n1,const node &n2){
	return n1.l<n2.l;
}
int find(int x){
	int l=1,r=dcnt;
	while(l<=r){
		int mid=(l+r)>>1;
		if(d[mid].l<x)l=mid+1;
		else r=mid-1;
	}
	return l;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1])f=0;
		if(!pos[a[i]]){
			pos[a[i]]=i;
		}
		else d[++dcnt]={pos[a[i]],i-1},pos[a[i]]=i;
	}
	if(f){
		for(int i=1;i<=m;i++)cout<<pos[i]<<' ';
		return 0;
	}
	if(m==2){
		int cnt1=0,cnt2=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1&&a[n]==1)cnt1++;
			else if(a[i]==1&&a[n]==2)cnt1++,cnt2++;
			else if(a[i]==2&&a[n]==1)cnt1++,cnt2++;
			else cnt2++;
		}
		cout<<cnt1<<' '<<cnt2;
		return 0;
	}
	sort(d+1,d+dcnt+1);
	for(int i=1;i<=n;i++){
		for(int j=find(i);j<=dcnt;){
			if(d[j].l<i)break;
			c[d[j].l]++,c[d[j].r+1]--;
			if(j==dcnt)break;
			j=find(d[j].r+1);
		}
	}
	for(int i=1;i<=n;i++){
		c[i]+=c[i-1];
	}
	for(int i=1;i<=m;i++)cout<<pos[i]-c[pos[i]]<<' ';
	return 0;
}
