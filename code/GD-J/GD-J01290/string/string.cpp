#include<iostream>
#define int long long
using namespace std;
int n;
struct node{
	int a;
	char c;
};
node a[200005];
int ans=0;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i].a>>a[i].c;
	}
	int l=1,r=n;
	while(l<r){
		if(a[l].a<a[r].a){
			if(a[l].c!=a[r].c){
				ans+=a[l].a;
			}
			a[r].a-=a[l].a;
			++l;
			continue;
		}
		else if(a[l].a>a[r].a){
			if(a[l].c!=a[r].c){
				ans+=a[r].a;
			}
			a[l].a-=a[r].a;
			--r;
			continue;
		}
		else{
			if(a[l].c!=a[r].c){
				ans+=a[l].a;
			}
			++l;
			--r;
		}
	}
	cout<<ans;
	return 0;
} 
