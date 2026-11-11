#include <bits/stdc++.h>

using namespace std;
const int N=2e5+10;
struct node{
	int b;
	char c;
}a[N];
int n,f,ba;
long long ans;

int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(register int i=1;i<=n;i++) cin>>a[i].b>>a[i].c;
	f=1,ba=n;
	while(f<ba){
		int cnt=min(a[f].b,a[ba].b);
		if(a[f].c!=a[ba].c){
			a[f].b-=cnt;
			a[ba].b-=cnt;
			ans+=cnt;
		}else{
			a[f].b-=cnt;
			a[ba].b-=cnt;
		}
		if(a[f].b==0) f++;
		if(a[ba].b==0) ba--;
	}
	cout<<ans;
	return 0;
}
