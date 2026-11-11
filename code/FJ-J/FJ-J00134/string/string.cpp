#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
struct dt{
	int a;
	char c;
}ls[N];
int n;
ll ans;
int main(){
//	freopen("string6.in","r",stdin);
//	freopen("string.out","w",stdout);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>ls[i].a>>ls[i].c;
	}
	int l=1,r=n;
	while(l<r){
		if(ls[l].c==ls[r].c){
			if(ls[l].a>ls[r].a){
				ls[l].a-=ls[r].a;
				ls[r].a=0;
				r--;
			}
			else if(ls[l].a<ls[r].a){
				ls[r].a-=ls[l].a;
				ls[l].a=0;
				l++;
			}
			else{
				ls[r].a=0;
				ls[l].a=0;
				l++;
				r--;
			}
		}
		else{
			if(ls[l].a>ls[r].a){
				ls[l].a-=ls[r].a;
				ans+=ls[r].a;
				ls[r].a=0;
				r--;
			}
			else if(ls[l].a<ls[r].a){
				ls[r].a-=ls[l].a;
				ans+=ls[l].a;
				ls[l].a=0;
				l++;
			}
			else{
				ans+=ls[r].a;
				ls[r].a=0;
				ls[l].a=0;
				l++;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}

