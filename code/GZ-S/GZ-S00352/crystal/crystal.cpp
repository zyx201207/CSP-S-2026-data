//GZ-S00352 遵义市第十二中学  李承昊 
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,a[N],s[N],ans;
long long m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(n<=5000){
		for(int i=1;i<n;i++) s[i]=s[i-1]+(a[i+1]-a[i])*i;
		for(int i=0;i<n;i++)
			for(int j=i;j<n;j++)
				if(s[j]-s[i]>m){
					ans=max(ans,j-i);
					break;
				}
	}
	else{
		int i=1,len=a[2]-a[1];
		while(m>0){
			m-=i*len,i++,ans++;
		}
		if(m<0) ans--;
	}
	cout<<ans;
	return 0; 
}

