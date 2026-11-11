#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long sum=0;
long long n;
struct Node{
	long long l,r;
	long long n;
	char m;
}a[N];
void get(long long t,long long x,char y){
	a[t].l=a[t-1].r+1;
	a[t].r=a[t].l+x-1;
	a[t].n=x;
	a[t].m=y;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long time=0;
	a[0].r=0;
	for(long long i=1;i<=n;i++){
		long long x;
		char y;
		cin>>x>>y;
		get(i,x,y);
		time+=x;
	}
	long long f=1,s=n;
	for(long long i=1;i<=time/2;i++){
		long long wei=time-i+1;
		char x,y;
		if(i>=a[f].l&&i<=a[f].r){
			x=a[f].m;
		}else{
			x=a[++f].m;
		}
		if(wei>=a[s].l&&wei<=a[s].r){
			y=a[s].m;
		}else{
			y=a[--s].m;
		}
		if(x!=y)sum++;
	}
	cout<<sum;
	return 0;
}
