#include<bits/stdc++.h>
using namespace std;
long long n,ans,l,r,flag,cnt;
char d;
struct node{
	long long x;
	char c;
}a[200010];
void p(){
	if(a[l].x>a[r].x){
		flag=1;
		a[l].x-=a[r].x;
	}else if(a[l].x<a[r].x){
		flag=2;
		a[r].x-=a[l].x;
	}else{
		flag=0;
		cnt=a[l].x;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1,x;i<=n;i++)cin>>a[i].x>>a[i].c;
	l=1,r=n;
	while(l<=r){
		p();
		if(a[l].c!=a[r].c){
			if(flag==1)ans+=a[r].x;
			else if(flag==2)ans+=a[l].x;
			else ans+=cnt;
		}
		if(flag==1)r--;
		else if(flag==2)l++;
		else r--,l++;
	}
	cout<<ans;
	return 0;
}
