#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],L,R,p,ans;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	for(int i=1,j=n;i<j;){
		if(c[i]!=c[j]){
			if((L+a[i])<(R+a[j])){
				if(p) ans+=a[i];//p=1±íL+ 
				else ans+=L+a[i]-R;//p=0±íR+
				p=1,L+=a[i],i++;
				continue; 
			}
			if((L+a[i])>(R+a[j])){
				if(p) ans+=R+a[j]-L;
				else ans+=a[j];
				p=0,R+=a[j],j--;
				continue;
			}
			if(p) ans+=a[i];
			else ans+=a[j];
			p=1,L+=a[i],R+=a[j],i++,j--;
			continue;
		}
		if((L+a[i]<(R+a[j]))){
			p=1,L+=a[i],i++;
			continue;
		}
		if((L+a[i]>(R+a[j]))){
			p=0,R+=a[j],j--;
			continue;
		}
		p=1,L+=a[i],R+=a[j],i++,j--;
	}
	cout<<ans;
	
	
	return 0;
} 
