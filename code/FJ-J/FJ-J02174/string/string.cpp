#include<bits/stdc++.h>
using namespace std;
struct E {
	long long num;
	char letter;
};
int n;
E a[200005];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	long long sz=0;
	for(int i=1; i<=n; i++) {
		cin>>a[i].num>>a[i].letter;
		sz+=a[i].num;
	}
	long long ans=0;
	long long l=1,r=n;
	while(l<r)
	{
		if(a[l].num>a[r].num){	
			if(a[l].letter!=a[r].letter) ans+=a[r].num;	
			a[l].num-=a[r].num;
			a[r].num=0;
		}
		else{
			if(a[l].letter!=a[r].letter) ans+=a[l].num;	
			a[r].num-=a[l].num;
			a[l].num=0;
		}
		if(a[l].num==0)l++;
		if(a[r].num==0)r--;
	}
	cout<<ans;
}
