#include<bits/stdc++.h>
using namespace std;
#define rd read()
#define ll long long
#define getpre(i,j) (i?pre[j]-pre[i-1]:pre[j])
const int BUF=1<<20;
char buf[BUF],*head=buf,*tail=buf;
inline char gc(){
	if(head==tail)head=buf,tail=buf+fread(buf,1,BUF,stdin);
	return head==tail?0:*head++;
}
inline long long read(){
	int n=0,k=1;
	char c=gc();
	while('0'>c||c>'9'){
		if(c=='-')k=-1;
		c=gc();
	}
	while('0'<=c&&c<='9'){
		n=n*10+c-'0';c=gc(); 
	}return n*k;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n=rd,m=rd;
	vector<ll> a(n);
	for(int i=0;i<n;i++)a[i]=rd+1000000000005LL;
	sort(a.begin(),a.end());
	queue<long long> q;
	long long res=0;
	long long ind=0;
	long long sum=0;
	vector<long long>pre(n);//pre[i]=add(a[0~i])
	pre[0]=a[0];
	for(int i=1;i<n;i++){
		pre[i]=a[i]+pre[i-1];
	}
	long long top=0;
	while(ind<n-1){
		q.push(a[ind]);
		sum+=a[ind];
		while(!q.empty()&&a[ind]*q.size()-getpre(top,ind)>m)sum-=q.front(),q.pop(),top++;
		res=max(res,(long long)q.size());
		ind++;
	} cout<<res;
	return 0;
}
