#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long cnt;
struct NODE{
	int s;
	char x;
}p[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i].s;
		cin>>p[i].x;
	}
	long long l=1,r=n;
	while(l<=r){
		if(p[l].s<=p[r].s){
			if(p[l].x!=p[r].x)cnt+=p[l].s;
			p[r].s-=p[l].s;
			l++;
		}
		else{
			if(p[l].x!=p[r].x)cnt+=p[r].s;
			p[l].s-=p[r].s;
			r--;
		}
	}cout<<cnt;

	return 0;
}
