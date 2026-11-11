#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n;
int a[N],sum[N];
char ch[N];
int ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(NULL),cout.tie(NULL);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> ch[i];
	}
	int lt=1,rt=n;
	while(lt<rt){
		if(a[lt]>a[rt]){
			a[lt]-=a[rt];
			if(ch[lt]!=ch[rt])ans=ans+a[rt];
			rt--;
		}else if(a[rt]>a[lt]){
			a[rt]-=a[lt];
			if(ch[lt]!=ch[rt])ans=ans+a[lt];
			lt++;
		}else{
			if(ch[lt]!=ch[rt])ans=ans+a[lt];
			lt++,rt--;
		}
	}
	cout << ans;
	return 0;
}