#include<bits/stdc++.h>
using namespace std;
int n,a[200005],ans=0,ans1=0,k=0;
char s[30];
string ss;
int main(){
	freopen("string1.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		ans+=a[i];
		for(int j=0;j<a[i];j++){
			ss[j]=s[i];
		}
	}
	ans/=2;
	ans1=ans+1;
	if(ans%2==1)ans1++;
	for(int i=0;i<ans;i++)for(int j=n-1;j>=ans1-1;j--)if(ss[i]!=ss[j])k++;
	cout<<k;
	return 0;
}
