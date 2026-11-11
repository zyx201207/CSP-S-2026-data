#include<bits/stdc++.h>
using namespace std;
long long a[200010];
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		if(i>0&&c[i]==c[i-1]){
			a[i-1]+=a[i];
			n--,i--;
		}
	}
	long long cnt=0,lp=0,rp=0
	for(int i=0;i<n/2;i++){
		if(c[i]!=c[n-i-1]){
			if(a[i]>a[n-i-1]){
				cnt+=min(a[i],a[n-i-1]-rp);
				rp+=a[i]-a[n-i-1];
			}
			else if(a[i]<a[n-i-1]){
				cnt+=min(a[i]-lp,a[n-i-1]);
				lp+=a[n-i-1]-a[i];
			}
		}
	}
	cout<<cnt+max(lp,rp);
	return 0;
}
/*
4 o
2 m
10 r
7 z
3 e
lp=5
rp=1
cnt=5
*/
