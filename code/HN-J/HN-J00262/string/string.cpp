#include<bits/stdc++.h>
using namespace std;
long long n;
struct node{
	long long s;
	char c;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].s>>a[i].c;	
	}
	long long l=1,r=n,sum=0;
	while(l<r){
		if(a[l].c!=a[r].c)
			sum+=min(a[l].s,a[r].s);
		if(a[l].s==a[r].s){
			l++;
			r--;
		}else if(a[l].s>a[r].s) {
			a[l].s-=a[r].s;
			r--;
		}else if(a[l].s<a[r].s){
			a[r].s-=a[l].s;
			l++;
		}
	}
	cout<<sum;
	return 0;
}

