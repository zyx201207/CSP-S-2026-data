#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct s{
	int a;
	char c;
}p[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i].a>>p[i].c;
	}
	for(int i=1;i<=n;i++){
		if(p[i].c!=p[n-i+1].c){
			cnt+=p[n-i+1].a;
		}
	}
	cout<<cnt;
	return 0;
}
