#include<bits/stdc++.h>
using namespace std;
char ch[2000005];
long long a[2000005],n,p1,p2,ans=0,m=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	p1=0;p2=n;
	for(int i=1;i<=n;i++)cin>>a[i]>>ch[i];
	while(p1<p2){
		if(ch[p1]==ch[p2])m=0;
		else m=1;
		if(a[p1]>a[p2]){
			ans+=a[p2]*m;
			a[p1]-=a[p2];
			a[p2]=0;
			p2--;
		}
		else if(a[p1]<a[p2]){
			ans+=a[p1]*m;
			a[p2]-=a[p1];
			a[p1]=0;
			p1++;
		}
		else if(a[p1]==a[p2]){
			ans+=a[p1]*m;
			a[p1]=0;
			a[p2]=0;
			p1++;
			p2--;
		}
	}cout<<ans;
	return 0;
}
