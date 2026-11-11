#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n;
long long sum,ans,mx;
bool f=true,num=true;
long long a[N];
char c[N];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%s",&a[i],&c[i]);
		if(c[i]!=c[i-1]) f=false;
		if(a[i]!=a[i-1]) num=false;
		mx=max(mx,a[i]);
		if(n<=2000&&mx<500){
			for(int j=1;j<=a[i];j++){
				s+=c[i];
			}
		}
		sum+=a[i];
	}
	if(f) printf("0");
	else if(num){
		for(int i=1;i<=n/2;i++){
			if(c[i]!=c[n-i+1]) ans+=a[i];
		}
		if(n%2==1){
			ans+=(a[1]+1)/2;
		}
		printf("%lld",ans);
	}else if(n<=2000&&mx<1000){
		for(int i=0;i<=sum/2;i++){
			if(s[i]!=s[sum-i-1]) ans++;
		}
		printf("%lld",ans);
	}else{
		bool flag=false;
		for(int i=1;i<=n/2;i++){
			if(a[i]!=a[n-i+1]||c[i]!=c[n-i+1]){
				flag=true;
				break;
			}
		}
		if(!flag){
			printf("0");
			return 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}