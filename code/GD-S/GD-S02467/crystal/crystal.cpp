#include<bits/stdc++.h>

using namespace std;
long long a[500005];
long long n,m;
struct node{
	long long c;
	long long b;
}q[500005];
bool cmp(node x,node y){
	return x.c<y.c;
}
int main(){
	ifstream("crystal.in");
	ofstream("crystal.out");
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n+1);
	q[1].c=a[1];
	q[1].b=1;
	for(int i=2;i<=n;i++){
		q[i].c=a[i]-a[i-1];
		q[i].b=i;
	}
	while(m>0){
		int o=1;
		sort(q,q+n+1,cmp);
		while(q[o].c==0)o++;
		if(q[o].c>m){
			m=0;
			continue;
		}
		else{
			a[q[o].b]+=q[o].c;
			m-=q[o].c;
		}
		sort(a+1,a+n+1);
		q[1].c=a[1];
		for(int i=2;i<=n;i++){
			q[i].c=a[i]-a[i-1];
		}
		sort(q,q+n+1,cmp);
	}
	int o=1,cnt=0;
	sort(a+1,a+n+1);
	q[1].c=a[1];
	for(int i=2;i<=n;i++){
		q[i].c=a[i]-a[i-1];
	}
	sort(q,q+n+1,cmp);
	while(q[o].c==0){
		if(o>n)break;
		o++;
		cnt++;
	}
	cout<<cnt;
} 
