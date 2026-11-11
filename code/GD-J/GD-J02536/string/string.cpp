#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
#define int long long
//#define cerr if(0)clog
struct zip{
	int n;
	char c;
};
zip ls[200200];
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>ls[i].n>>ls[i].c;
	}
	int l=1,r=n;
	int ret=0;
	while(l<r){
		int len=min(ls[l].n,ls[r].n);
		if(ls[l].c!=ls[r].c){
			ret+=len;
		}
		ls[l].n-=len;
		ls[r].n-=len;
		if(ls[l].n==0)l++;
		if(ls[r].n==0)r--;
	}
	cout<<ret;
}
