#include<bits/stdc++.h>
using namespace std;
long long q,x,len,ans,i,j;
char y;
long long a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>q;
	while(q--){
		cin>>x>>y;
		if(!len||c[len]!=y)len++,a[len]=x,c[len]=y;
		else if(c[len]==y)a[len]+=x;
	}
	for(i=1,j=len;i<=j;){
		if(c[i]!=c[j]){
			ans+=min(a[i],a[j]);
			if(a[i]>a[j])a[i]-=a[j],a[j]=0,c[j]=0,j--;
			else if(a[i]<a[j])a[j]-=a[i],a[i]=0,c[i]=0,i++;
			else a[i]=a[j]=0,c[i]=c[j]=0,i++,j--;
		}
		else if(c[i]==c[j]&&a[i]!=a[j]){
			if(a[i]>a[j])a[i]-=a[j],a[j]=0,c[j]=0,j--;
			if(a[i]<a[j])a[j]-=a[i],a[i]=0,c[i]=0,i--;
		}
		else i++,j--;
	}
	cout<<ans;
	return 0;
}
