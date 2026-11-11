#include<bits/stdc++.h>
using namespace std;
int s[1000000];
char c[1000000];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,cnt,ans=0,xiang=0;
	cin>>n;
	cnt=n;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>c[i];
		xiang+=s[i];
	}
	for(int i=n;i>=1;i--){
		if(c[i]==c[i-1]){
			c[i]=' ';
			s[i-1]+=s[i];
			cnt--;
		}
	}
	if(s[1]>(cnt+1)/2&&cnt>1){
		cout<<xiang-s[1];
		return 0;
	}
	if(s[cnt]>(cnt+1)/2&&cnt>1){
		cout<<xiang-s[cnt];
		return 0;
	}
	for(int i=1;i<=(cnt+1)/2;i++){
		if(s[i]==s[cnt+1-i]&&c[i]==s[cnt+1-i]){
			continue;
		}
		if(c[i]==c[cnt+1-i]){
			if(s[i]>s[cnt+1-i]){
				ans+=s[i]-s[cnt+1-i];
				s[cnt-i]-=s[i]-s[cnt+1-i];
			}
			else{
				ans-=s[i]-s[cnt+1-i];
				s[i+1]+=s[i]-s[cnt+1-i];
			}
			continue;
		}
		if(s[i]==s[cnt+1-i]){
			ans+=s[i];
			continue;
		}
		ans+=max(s[i],s[cnt+1-i]);
		
	}
	cout<<ans;
	return 0;
}
