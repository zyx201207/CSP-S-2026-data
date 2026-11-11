//GZ-J00251   遵义市第五十三中学 王前进 
#include <bits/stdc++.h>
using namespace std;
long long n;
//ll a[200010];
string s;
struct A{
	long long ai;
	char ci;
}a[200010];
bool chage(string s){
	long long len=s.size()-1;
	for(long long i=0;i<=len/2;i++){
		if(s[i]!=s[len-i]) return 0;
	}
	return 1;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	scanf("%lld",&n);
	if(n==1){
		cout<<0; return 0;
	}
	long long sum=0,maxn=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i].ai>>a[i].ci;
		sum+=a[i].ai;
		s+=a[i].ci;
		maxn=max(maxn,a[i].ai);
	}
	if(chage(s)==1){
		cout<<0;
		return 0;
	}
	if(maxn>=sum/2){
		cout<<sum-maxn;
		return 0;
	}
	long long cnt=0,ans=0;
	for(int i=1;i<=n;i++){
		for(int j=2;j<=n;j++){
			if(s[j]!=s[i]){
				s[j]=s[i];cnt++;
			}
			if(chage(s)){
				ans=min(ans,cnt);
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

