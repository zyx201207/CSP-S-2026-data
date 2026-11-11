#include<iostream>
#include<algorithm>
using namespace std;
struct node{
	int val;
	int op;
	int book;
}a[200005];
int n2[31]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824};
int n,m;
int ans;
int upper(int l,int r,int x){
	while(l<r){
		int mid=(l+r)>>1;
		if(a[mid].op==x) return mid;
		else if(a[mid].op>x) r=mid;
		else l=mid+1;
	}
	return l;
}
bool cmp(node a,node b){
	return a.op>b.op;
}
void f(int l){
	if(n-l+1==m){
		ans=a[l].val;
		for(int i=l+1;i<=n;i++) ans=ans&a[i].val;
		return;
	}
	int ln=0;
	for(int i=l;i<=n;i++)
		if(a[i].val==a[l].val) ln++;
	else break;
	if(n-l+1-ln<=m){
		ans=a[n-m+1].val;
		for(int i=n-m+2;i<=n;i++) ans=ans&a[i].val;
		return;
	}
	int l1;
	for(int i=30;i>=0;i--)
		if(n2[i]<a[n-m+1].op){
			l1=n2[i];
			break;
		}
	int l2=upper(l,n,l1);
	for(int i=l2;i<=n;i++) a[i].op=a[i].op&(l1-1);
	sort(a+l2,a+n+1,cmp);
	f(l2);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].val;
		a[i].op=a[i].val;
	}
	sort(a+1,a+n+1,cmp);
	f(1);
	cout<<ans;
	return 0;
}
