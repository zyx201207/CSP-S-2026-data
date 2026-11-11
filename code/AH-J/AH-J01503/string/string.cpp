#include<bits/stdc++.h>
using namespace std;
long long n,a[200050],s=0,t1=1,t2,s1,s2,ans=0;
char b[200050];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		s+=a[i];
	}
	t2=n;
	while(t1!=t2){
		if(b[t1]!=b[t2]){
			int t=min(a[t1],a[t2]);
			ans+=t;
			a[t1]-=t,a[t2]-=t;
		}else if(b[t1]==b[t2]){
			int t=min(a[t1],a[t2]);
			a[t1]-=t,a[t2]-=t;
		}
		if(a[t1]==0) t1++;
		else if(a[t2]==0) t2--;
	}
	cout<<ans;
	return 0;
}
