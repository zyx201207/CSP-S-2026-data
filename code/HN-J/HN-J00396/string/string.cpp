#include<bits/stdc++.h>
using namespace std;
const int M=2*1e5+3;
struct node{
	long long m;
	char c;
};
long long n;
node a[M];
long long l=1,r,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].m>>a[i].c;
	}
	r=n;
	while(l<=r){
		long long maxx=a[l].m>a[r].m?a[l].m:a[r].m;
		long long minn=a[l].m<a[r].m?a[l].m:a[r].m;
		bool b=a[l].m>a[r].m?1:0;
		if(a[l].c!=a[r].c)ans+=minn;
		if(maxx==minn){
			l++;
			r--;
		}
		else if(b){
			a[l].m-=a[r].m;
			r--;
		}
		else{
			a[r].m-=a[l].m;
			l++;
		}
	}
	cout<<ans;
	return 0;
}
