#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,cnt,maxn;
struct node{
	long long x,len;
}a[500005];
int cmp(node l,node r){
	return r.x>l.x;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int flag1=1;
	for(int i=1;i<=n;i++){
		cin>>a[i].x;
		if(flag1&&i!=1){
			if(a[i].x!=a[i-1].x){
				flag1=0;
			}
		}
	}
	if(flag1){
		cout<<n;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		a[i].len=abs(a[i].x-a[i-1].x);
	}
	for(int si=1;si<=n;si++){
		for(int ei=si;ei<=n;ei++){
			long long t=m,flag2=1,flagqi=0;
			for(int i=si;i<=ei;i++){
				if(t>=a[i].len&&flag2){
					if(i==si&&i!=1&&a[i].len!=a[i-1].len){
						flagqi=1;
					}
					t-=a[i].len;
					cnt++;
				}else{
					flag2=0;
				}
			}
			if(flagqi&&t>0){
				cnt++;
			}
			maxn=max(maxn,cnt);
			cnt=0;
		}
	}
	cout<<maxn;
	return 0;
} 
