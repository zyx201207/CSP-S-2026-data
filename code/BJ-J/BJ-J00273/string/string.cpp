#include<bits/stdc++.h>
using namespace std;
int n;
struct st{
	int a;
	char c;
};
st g[200005];
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>g[i].a>>g[i].c;
	}
	int l=1,r=n; 
	int sl=g[l].a,sr=g[r].a;
	while(l<r){
		for(;sl>0;sl--){
			if(g[l].c!=g[r].c){
				ans++;
			}
			sr--;
			if(sr==0){
				r--;
				sr=g[r].a;
			}
		}
		l++;
		sl=g[l].a;
	}
	cout<<ans;
	return 0;
}
