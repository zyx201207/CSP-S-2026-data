#include<bits/stdc++.h>

using namespace std;
char a[30000005];
char d[1000005];
long long k=0,ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int b;
		char c;
		cin>>b>>c;
		for(int i=1;i<=b;i++){
			a[k+i]=c;
		}
		k+=b;
	}
	if(k%2==0){
		int l=k/2,r=k/2+1;
		for(int i=1;i<=k/2;i++){
			if(a[l]!=a[r])ans++;
			l--;
			r++;
		}
	}else {
		int l=k/2,r=k/2+2;
		for(int i=1;i<=k/2;i++){
			if(a[l]!=a[r])ans++;
			l--;
			r++;
		}
	}
	cout<<ans;
//	solve();
	return 0;
}

