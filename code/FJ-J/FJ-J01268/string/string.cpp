#include<bits/stdc++.h>
using namespace std;
struct node{
	long long x;char y;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;long long len=0,cnt=0;
	cin>>n;
	string s;
	vector<node> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i].x>>a[i].y;
	}
	len=n-1;
	int head=0;
	for(;len>=n/2;){
		if(a[len].y!=a[head].y){
			cnt+=min(a[len].x,a[head].x);
			
		}
		if(a[len].x>a[head].x){
			a[len].x-=a[head].x;
			head++;
		}else{
			a[head].x-=a[len].x;
			len--;
		}
	}
	cout<<cnt;
	return 0;
}

