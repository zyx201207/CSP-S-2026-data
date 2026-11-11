#include<bits/stdc++.h>
using namespace std;
const int N=1e8+5;
struct node{
	int a;
	int cnt;
}nd[N];
int d[N];
int jz(int a){
	if(a==0)return 0;
	int k=1;
	while(a>0){
		d[k++]=a%2;
		a/=2;
	}
	int sum=0;
	for(int i=1;i<=k;i++){
		if(d[i]==1)sum+=1;
	}
	return sum;
}
bool cmp(node a,node b){
	if(a.cnt>b.cnt)return a.cnt>b.cnt;
	else if(a.cnt<b.cnt)return a.cnt>b.cnt;
	else{
		if(a.a>=b.a)return a.a>=b.a;
		else return a.a>b.a;
	}
}
int main(){
	freopen("and2.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(m==0){
		cout<<0;return 0;	
	}
	for(int i=1;i<=n;i++){
		cin>>nd[i].a;
		nd[i].cnt=jz(nd[i].a);
	}
	sort(nd+1,nd+n+1,cmp);
	int sum=nd[1].a;
	for(int i=2;i<=m;i++){
		sum&=nd[i].a;
	}
	cout<<sum;
	return 0;
}

