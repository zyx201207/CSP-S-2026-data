#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a[1000000],cnt=0,ans=0;
	cin>>n;
	char c[10000000];
	string b="";
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			b+=c[i];
			cnt++;
		}
	}
	for(int j=1;j<=(cnt+1)/2;j++){
			if(b[j]!=b[cnt-j+1])ans++;
		}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
	}
