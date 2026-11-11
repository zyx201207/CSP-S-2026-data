#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int n,m;
int a[N],b[N],nex[N];
int sum[N],w[N];
int lowbit(int x){return (x&-x);}
void change(int x,int y){
	for(int i=x;i<=n;i+=lowbit(i))sum[i]+=y;
}
int query(int x){
	int summ=0;
	for(int i=x;i;i-=lowbit(i))summ+=sum[i];
	return summ;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(b[a[i]]){
			nex[b[a[i]]]=i;
		}
		b[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		int v=query(i)+i;
		if(nex[i]>0){
			change(i+1,-v);change(nex[i],v);
		}
		w[a[i]]=max(w[a[i]],v);
	}
	for(int i=1;i<=m;i++)printf("%d ",w[i]);
	return 0;
} 
