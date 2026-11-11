#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e5+10;
LL a[N],ans;char s[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}for(int i=1,j=n;i<j;){
		if(a[i]<=a[j]){
			if(s[i]!=s[j])ans+=a[i];
			a[j]-=a[i];i++;
		}
		else{
			if(s[i]!=s[j])ans+=a[j];
			a[i]-=a[j];j--;
		}
	}
	cout<<ans;
	return 0;
}
