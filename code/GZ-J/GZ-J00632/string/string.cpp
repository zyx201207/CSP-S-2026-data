// GZ-J00632 贵阳市第一中学 谭心民 
#include<bits/stdc++.h>
using namespace std;
int n,ans,cnt,z,h;string s;
int a[200004];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		h+=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			cnt++;z=cnt;
			for(int q=n;q>=1;q--){
				if(z<=a[q]){
					if(s[i]!=s[q])ans++;
					break;					
				}
				else z-=a[q];
			}
			if(cnt==h/2)break;
		}
		if(cnt==h/2)break;
	}
	cout<<ans;
} 
