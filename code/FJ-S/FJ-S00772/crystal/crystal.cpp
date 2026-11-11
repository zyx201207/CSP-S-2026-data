#include <bits/stdc++.h>
using namespace std;

const int N=5e5+10;

struct u{
	int c,id;
}b[N];

bool cmp(u x,u y){
	return x.c<y.c;
}

long long n,m;
double sum;
long long a[N],bb,cnt=1;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	sum=sum/n*1.0;
	for(int i=1;i<=n;i++){
		b[i].c=abs(sum-a[i]);
		b[i].id=i;
	}
	sort(b+1,b+n+1,cmp);
	bb=a[b[1].id];
	int c=m,o=2;
	while(c>0){
		cnt++;
		c=c-(bb-a[b[o].id]);
		o++;
	}
	if(c<0){
		cnt--;
	}
	cout<<cnt;
	return 0;
}
