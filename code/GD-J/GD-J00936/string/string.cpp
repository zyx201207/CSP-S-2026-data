#include<bits/stdc++.h>
using namespace std;
using ll=long long;
struct pt{
	long long n;
	char zf;
} a[200005];
int n;
long long ahe;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld %c",&a[i].n,&a[i].zf);
		ahe=max(ahe,a[i].n);
	}
	if(ahe<=50){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i].n;j++) s=s+a[i].zf;
		}
		long long ans=0;
		for(int i=0;i<s.size()/2;i++){
			if(s[i]!=s[s.size()-i-1]){
				ans++;
			}
		}
		printf("%lld",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

