#include<iostream>
#include<cstring>
using namespace std;
#define int long long

void solve(){
	string word;
	int n;
	scanf("%lld",&n);
	for (int i=1;i<=n;i++){
		int a;
		char s;
		scanf("%lld %c",&a,&s);
		for (int j=1;j<=a;j++) word+=s;
	}	
	int w=word.size(),ans=0;
	for (int i=0;i<w/2;i++){
		if (word[i]!=word[w-1-i]){
			ans++;
		}
	}
	printf("%lld\n",ans);	
	return ;
}

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	solve();
	
	return 0;
}
