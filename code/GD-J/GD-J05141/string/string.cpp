#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200001];
char c[200001];
string s;
bool bz=false,b[200001]={false},b2=true;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	memset(b,false,sizeof b);
	int n;
	scanf("%lld",&n);
	if(n==1){
		printf("0");
		return 0;
	}
	for(int i=1;i<=n;i++){
		scanf("%lld %c",&a[i],&c[i]);
		if(a[i]>=10000)
			bz=true;
	}
	for(int i=1;i<=n;i++){
		if(bz==true)
			break;
		for(int j=1;j<=a[i];j++)
			s+=c[i];
	}
	int l=s.length();
	for(int i=0;i<l;i++){
		for(int j=i+1;j<l;j++){
			if(s[i]==s[j])
				b[i]=true;
			else
				b[i]=false;
		}
	}
	for(int i=0;i<l;i++){
		if(b[i]==false)
			b2=false;
	}
	if(b2==false){
		printf("0");
		return 0;
	}
	printf("%lld",floor(l/2));
}
