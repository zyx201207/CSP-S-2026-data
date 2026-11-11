#include<bits/stdc++.h>
using namespace std;

int a[200010];
char c[200010];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	long long n;
	scanf("%lld",&n);
	
	vector<char>v;
	for(int i=1;i<=n;i++){
		scanf("%d %c",&a[i],&c[i]);
		for(int j=1;j<=a[i];j++){
			v.push_back(c[i]);
		}
	}
	long long ans=0;
	for(int i=0;i<=v.size()-i-1;i++){
		ans+=v[i]!=v[v.size()-i-1];
	}
	printf("%lld",ans);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

