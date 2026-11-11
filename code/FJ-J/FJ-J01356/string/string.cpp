#include<bits/stdc++.h>
using namespace std;
struct Duan{
	long long len,i;
	char c;
	bool f(long long n){
		return n>=i&&n<i+len;
	}
}a[200005],t;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,k=0,l=0,r=0,sumlen=0,cnt=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>t.len>>t.c;
		t.i=sumlen;
		sumlen+=t.len;
		if(k==0||t.c!=a[k-1].c){
			a[k++]=t;
		}else a[k-1].len+=t.len;
	}
	if(k==1){
		cout<<0;
		return 0;
	}
	r=k-1;
	for(long long i=0;i<sumlen-i-1&&l<r;i++){
		while(!a[l].f(i)) l++;
		while(!a[r].f(sumlen-i-1)) r--;
		if(l>=r) break;
		if(a[l].c!=a[r].c) cnt++;
	}
	cout<<cnt;
	return 0;
}