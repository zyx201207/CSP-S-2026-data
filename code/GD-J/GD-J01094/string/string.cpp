#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 200005
int n;
int ans;
int num[N];
char ch[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>num[i]>>ch[i];
	int l=1,r=n;
	while(r>l){
		if(num[l]>num[r]){
			if(ch[l]!=ch[r]) ans+=num[r];
			num[l]-=num[r];
			r--;
		}
		else {
			if(ch[l]!=ch[r]) ans+=num[l];
			num[r]-=num[l];
			l++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
