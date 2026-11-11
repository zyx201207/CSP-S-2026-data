#include<bits/stdc++.h>
using namespace std;
long long n,ans=0,l;
char r;
struct DF{
	int d;
	char c;
}a[200100],b[200100];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1,j=n;i<=n;i++,j--){
		cin>>l>>r;
		a[i].c=b[j].c=r,a[i].d=b[j].d=l;
	}
	for(int i=1;i<=n;i++){
		if(a[i].c!=b[i].c){
			ans+=min(a[i].d,b[i].d);
			if(a[i].d<b[i].d) a[i].c=b[i].c;
			else b[i].c=a[i].c;
		}
	}
	cout<<ans;
	return 0;
}
