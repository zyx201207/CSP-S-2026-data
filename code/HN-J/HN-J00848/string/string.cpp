#include<bits/stdc++.h>
using namespace std;
int n;
char c[100000010];
long long num;
int ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
//	cout<<2000*50<<endl<<2*100000;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int a;
		char x;
		cin>>a>>x;
		for(long long j=1;j<=a;j++){
			c[num+j]=x;
		}
		num+=a;
	}
	/*for(int i=1;i<=num;i++)cout<<c[i];
	cout<<endl;
	for(int i=1;i<=num;i++){
		c1[num+1-i]=c[i];
	}
	for(int i=1;i<=num;i++)cout<<c1[i];*/
	for(int i=1;i<=num/2;i++){
		if(c[i]!=c[num+1-i])ans++;
	}
	printf("%d",ans);
	return 0;
}
