#include<bits/stdc++.h>
#define int long long
const int N=2e5+10;
const int INF=0x3f3f3f3f; 
using namespace std;
int n,len=0;
int ans=0;
struct node{
	int a;
	char c;
}x[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i].a>>x[i].c;
	}
	int l=1,r=n;
	while(l<=r){
		if(x[l].c==x[r].c){
			if(x[l].a>x[r].a){
				x[l].a-=x[r].a;
				r--;
			}
			else if(x[l].a<x[r].a){
				x[r].a-=x[l].a;
				l++;
			}
			else{
				l++;
				r--;
				continue;
			}
		}
		else{
			if(x[l].a>x[r].a){
				x[l].a-=x[r].a;
				ans+=x[r].a;
				r--;
			}
			else if(x[l].a<x[r].a){
				x[r].a-=x[l].a;
				ans+=x[l].a;
				l++;
			}
			else{
				ans+=x[l].a;
				l++;
				r--;
				continue;
			}
		}
	}
	cout<<ans;
}
