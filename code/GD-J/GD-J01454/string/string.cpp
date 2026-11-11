#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
struct hwc{
	int x;
	char y;
}a[N],b[N];
long long n,l,cnt;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n+1;i++){
		if(i<=n)cin>>a[i].x>>a[i].y;
		if(a[i].y==a[i-1].y){
			a[i-1].x=a[i].x+a[i-1].x;
			a[i].x=0;
		    a[i].y='#';
		}
		if(a[i-1].x!=0){
			l++;
			b[l].x=a[i-1].x;
			b[l].y=a[i-1].y;
		}
	}
	cout<<0;
	return 0;
}
