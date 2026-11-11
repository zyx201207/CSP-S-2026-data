#include<bits/stdc++.h>
using namespace std;
int cnt;
int n,sum;
struct st{
	char c;
	unsigned int c_begin=0,c_end=0;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	st a[172848];
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>a[i].c;
		a[i].c_begin=a[i-1].c_end+1;
		a[i].c_end=a[i].c_begin+n-1;
		sum+=n;
	}
	int l=1,r=sum;
	int ll=1,rr=t;
	while(l<r){
		if(a[ll].c!=a[rr].c){
			cnt++;
		}
		l++;
		r--;
		if(l>a[ll].c_end){
			ll++;
		}
		if(r<a[rr].c_begin){
			rr--;
		}
	}
	cout<<cnt;
	return 0;
}
