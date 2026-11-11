#include<bits/stdc++.h>
using namespace std;
#define filename "string"
const int N=2e5+10;
int n;
int a[N];
char c[N];
int main(){ 
	freopen(filename".in","r",stdin);
	freopen(filename".out","w",stdout);
	scanf("%d",&n);
	if(n==1){
		cout<<0;
		return 0;
	}
	if(n<=200010){
		string s;
		s=' '+s;
		int sum=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			sum+=a[i];
			char cc;
			cin>>cc;
			for(int j=1;j<=a[i];j++){
				s+=cc;
			}
		}
//		cout<<s<<" "<<sum<<'\n';
		int ans=0;
		for(int i=1;i<=sum/2;i++){
			if(s[i]!=s[sum+1-i])ans++;
		}
		cout<<ans<<'\n';
		return 0;
	}
	return 0;
}
//Trick||Treat!
