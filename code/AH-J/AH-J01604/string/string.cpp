#include<bits/stdc++.h>
using namespace std;
struct Node{
	long long a;
	char c;
}k[200010];
long long cnt;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>k[i].a>>k[i].c;
	int l=1,r=n;
	while(l<r&&k[l].c!=k[r].c){
		if(k[l].a<k[r].a){
			cnt+=k[l].a;
			k[r].a-=k[l].a;
			l++;
		}
		if(k[l].a==k[r].a&&k[l].c!=k[r].c){
			cnt+=k[r].a;
			l++;
			r--;
		}
		if(k[l].a>k[r].a&&k[l].c!=k[r].c){
			cnt+=k[r].a;
			k[l].a-=k[r].a;
			r--;
		}
	}
	cout<<cnt;
	
	return 0;
}
