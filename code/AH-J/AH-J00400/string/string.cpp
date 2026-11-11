#include<bits/stdc++.h>
using namespace std;
struct p{
	char c;
	int x;
}a[200010];
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long l=1,lpos=0,r=n,rpos=0,h=0,ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
		h+=a[i].x;
	}
	while(l<r&&l<=n&&r>=1){
		if(a[l].x+lpos<a[r].x+rpos){
			lpos+=a[l].x;rpos+=a[l].x;
			a[r].x-=a[l].x;
			if(a[l].c!=a[r].c)ans+=a[l].x;
			l++;
		}else if(a[l].x+lpos>a[r].x+rpos){
			lpos+=a[r].x;rpos+=a[r].x;
			a[l].x-=a[r].x;
			if(a[l].c!=a[r].c)ans+=a[r].x;
			r--;
		}else{
			lpos+=a[l].x,rpos+=a[l].x;
			if(a[l].c!=a[r].c)ans+=a[r].x;
			l++,r--;
		}
	}
	cout<<ans;
}
