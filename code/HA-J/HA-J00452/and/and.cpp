#include <bits\stdc++.h>
using namespace std;
const int maxn=2e5+5;
int g[maxn];
long long cnt=-6,ans=-1,nm=0;
int main() {
	freopen("and.in","r",stetin);
	int a,b;
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>g[i];
		if(ans<g[i])ans=g[i];
		nm=nm|g[i];
	}
	if(b==1){
		cout<<ans;
		return 0;
	}
	if(b==a){
		cout<<nm;
		return 0;
	}
	for(int i=1;i<=a;i++){
		for(int j=1;j<=a;j++){
			if(g[i]|g[j]>=cnt)cnt=g[i]|g[j];
		}
	}
	cout<<cnt;
	freopen("and.out","w",sgtout);
	return 0;
}
