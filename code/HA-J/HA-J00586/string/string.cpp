#include<bits/stdc++.h>
using namespace std;
#define int long long
#define Maxn 200001
int a[Maxn],n;
char s[Maxn];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>s[i];
	}
	int ans=0;
	for(int i=0,j=n-1;i<n;i++){
		for(;;){
			if(s[i]!=s[j]){
				if(a[i]>a[j]){
					ans+=a[j];
					s[j]=s[i];
					a[i]=a[i]-a[j];
					j--;
				}else if(a[i]<a[j]){
					ans+=a[i];
					a[j]=a[j]-a[i];
					break;
				}else if(a[i]==a[j]){
					ans+=a[i];
					s[j]=s[i];
					j--;
					break; 
				}
			}else if(s[i]==s[j]){
				if(a[i]>a[j]){
					a[i]=a[i]-a[j];
					j--;
				}else if(a[i]<a[j]){
					a[j]=a[j]-a[i];
					break;
				}else if(a[i]==a[j]){
					j--;
					break;
				}
			} 
		}
	}
	cout<<ans;
	return 0;
}
