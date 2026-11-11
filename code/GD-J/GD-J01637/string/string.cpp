#include<bits/stdc++.h>
using namespace std;
int a[200010];	
int i,j;
char s[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long ans=0;
	cin>>n;
	for(int k=1;k<=n;k++)cin>>a[k]>>s[k];
	i=1,j=n;
	while(i<j){
		if(a[i]>a[j]){
			if(s[i]==s[j])a[i]-=a[j],a[j]=0;
			else ans+=a[j],a[i]-=a[j],a[j]=0;
			j--;
		}else if(a[i]<a[j]){
			if(s[i]==s[j])a[j]-=a[i],a[i]=0;
			else ans+=a[i],a[j]-=a[i],a[i]=0;
			i++;
		}else{
			if(s[i]==s[j])a[i]=0,a[j]=0;
			else ans+=a[i],a[i]=0,a[j]=0;
			i++,j--;
		}
		//cout<<i<<" "<<j<<'\n';
		//for(int i=1;i<=n;i++)cout<<a[i]<<' ';
		//cout<<'\n';
		
	}
	
	cout<<ans;
	return 0;
}

