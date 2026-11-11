#include<bits/stdc++.h>
using namespace std;
#define rd read()
const int BUF=1<<20;
char buf[BUF],*head=buf,*tail=buf;
char out[BUF];
int ops=0;
inline char gc(){
	if(head==tail)head=buf,tail=buf+fread(buf,1,BUF,stdin);
	return head==tail?0:*head++;
}
inline long long read() {
	int n=0,f=1;
	char c=gc();
	while('0'>c||c>'9'){
		if(c=='-')f=-1;c=gc();
	}
	while('0'<=c&&c<='9')n=n*10+c-'0',c=gc();
	return n*f;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n=rd;int m=rd;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		a[i]=rd;
	}
	sort(a.rbegin(),a.rend());
	int res=(unsigned int )-1;
	for(int i=0;i<m;i++){
		res=res&a[i];//cout<<res<<' ';
	}cout<<res;
	return 0;
}
