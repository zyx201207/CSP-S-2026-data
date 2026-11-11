#include <bits/stdc++.h>
using namespace std;
const int N=2e5;
struct node{
	long long x;
	char c;
};
int n;
long long ans,sum;
node a[N+5];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
		sum+=a[i].x;
	}
	long long l=0,r=0;
	for(int i=1,j=n;l<sum/2;i++){
		l+=a[i].x;
		if(l>=sum/2)	l=sum/2;
		while(r<l){
			if(r+a[j].x>l){
				if(a[j].c!=a[i].c){
					ans+=l-r;
				}
				a[j].x-=l-r;
				r=l;
			}
			else{
				if(a[j].c!=a[i].c){
					ans+=a[j].x;
				}
				r+=a[j].x;
				j--;
			}
		}
	}
	cout<<ans;
	return 0;
}
