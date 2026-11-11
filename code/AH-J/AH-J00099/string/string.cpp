#include<bits/stdc++.h>
using namespace std;
struct node{
	long long len;
	char c;
}a[200010];
long long n;
long long hw(){
	long long r=1,l=n,cnt=0;
	while(r<=l){
		if(a[r].c!=a[l].c){
			cnt=cnt+min(a[r].len,a[l].len);
		}
		if(a[r].len>a[l].len){
			a[r].len=a[r].len-a[l].len;
			l--;
		}else if(a[r].len<a[l].len){
			a[l].len=a[l].len-a[r].len;
			r++;
		}else if(a[r].len=a[l].len){
			l--;
			r++;
		}
	}
	return cnt;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i].len>>a[i].c;
	}
	cout<<hw();
	return 0;
}
