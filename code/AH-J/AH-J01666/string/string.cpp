#include<bits/stdc++.h>
using namespace std;
const int N=200100;
long long n,a[N],p[N],k,cnt=0,ans=0;
char s[N],m;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	
	for(int i=1;i<=n;i++){
		cin>>k>>m;
		if(i==1){
			s[cnt]=m;
			a[cnt]=k;
			continue;
		} 
		if(m==s[cnt])a[cnt]+=k;
		else{
			cnt++;
			s[cnt]=m;
			a[cnt]=k;
		}
	}
	for(int j=0;j<=cnt/2;j++){
		int i=j,g=cnt-j;
		while(p[i]==1){
			i++;
		}
		if(s[i]!=s[g]){
			if(a[i]>=a[g]){
				s[g]=s[i];
				ans+=a[g];
				if(s[g-1]==s[g]){
					a[g]+=a[g-1];
					p[g-1]=1;
				}
			}else if(a[i]<a[g]){
				s[i]=s[g];
				ans+=a[i]; 
				if(s[i+1]==s[i]){
					a[i]+=a[i+1];
					p[i+1]=1;
				}
			}
		}
		if(abs(i-(g))<=1)continue;
		if(a[i]<a[g]){
			int kh=0;
			for(int y=i+1;y<=cnt;y++){
				kh+=a[y];
				a[y]=0;
				if(kh>=a[g]-a[i]){
					a[y]=kh-(a[g]-a[i]);
					if(a[y]==0)p[y]=1;
					break;
				}
				p[y]=1;
			}
			ans=ans+a[g]-a[i];
			a[i]=a[g];
		}
		if(a[i]>a[g]){
			int kh=0;
			for(int y=g-1;y>0;y--){
				kh+=a[y];
				a[y]=0;
				if(kh>=a[i]-a[g]){
					a[y]=kh-(a[i]-a[g]);
					if(a[y]==0)p[y]=1;
					break;
				}
				p[y]=1;
			}
			ans=ans+a[i]-a[g];
			a[g]=a[i];
		}
	}
	cout<<ans;
	return 0;
}
