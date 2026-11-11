#include <bits/stdc++.h>
using namespace std;
long long n,a[100005],b[100005],ans;
char s[100005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i];
		cin>>s[i];
		a[i]=b[i];
	}for(int i=1,j=n;i<j;){
		if(s[i]==s[j]){
			a[i]-=min(a[i],a[j]);
			a[j]-=min(a[i],a[j]);
		}else{
			if(a[i]==a[j]){
				ans+=min(a[i],a[j]);
				a[i]=0;
				a[j]=0;
			}else{
				ans+=min(a[i],a[j]);
				a[i]-=min(a[i],a[j]);
				a[j]-=min(a[i],a[j]);
			}
		}if(a[i]==0) i++;
		if(a[j]==0) j--;
	}
	cout<<ans;
	return 0;
} 
