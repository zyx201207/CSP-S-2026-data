#include<bits\stdc++.h>
using namespace std;
long long n,a[200010],he[200010],z,ans;
char s[200010];
bool hw=1,e=0;
string S,Sf;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	scanf("%lld",a+1);
	he[1]=a[1];
	cin>>s[1];
	for(int j=1;j<=a[1];j++){
		S+=s[1];
	}
	for(int i=2;i<=n;i++){
		scanf("%lld",a+i);
		cin>>s[i];
		if(s[i]!=s[i-1])hw=0;
		he[i]=he[i-1]+a[i];
		for(int j=1;j<=a[i];j++){
			S+=s[i];
		}
	}
	
	if(hw){
		cout<<0;
		return 0;
	}
	for(int i=he[n]-1;i>=0;i--){
		Sf+=S[i];
	}
	for(int i=he[n]-1;i>=0;i--){
		if(Sf[i]!=S[i])ans++;
	}
	cout<<ans/2;
//	if(he%2==0){
//		z=he/2;
//		e=1;
//	}else z=n/2+1;
	
	return 0;
}
