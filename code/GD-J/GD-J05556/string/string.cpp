#include<bits/stdc++.h>
using namespace std;
int n,m,t,sum,cnt,b[1001],maxx;
bool f;
struct node{
	int k,cnt;
	int x[1001];
}a[200001];
bool cmp(node x,node y){
	return x.cnt>y.cnt;
}
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	cin>>n>>m;
	maxx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].k;
		a[i].cnt=0;
		t=0;
		while(a[i].k>0){
			t++;
			a[i].x[t]=a[i].k%2;
			if(a[i].x[t]==1) a[i].cnt++;
			a[i].k/=2;
		}
		if(t>maxx) maxx=t;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=maxx;i++){
		f=1;
		for(int j=1;j<=m;j++){
			if(a[j].x[i]==0) f=0;
		}
		if(f==1) b[i]=1;
		else b[i]=0;
	}
	t=maxx;
	while(b[t]==0) t--;
	cnt=1;
	sum=0;
	for(int i=t;i>=1;i--){
		sum+=b[i]*cnt;
		cnt*=2;
	}
	cout<<sum;
	return 0;
} 
