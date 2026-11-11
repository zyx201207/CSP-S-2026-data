#include<bits/stdc++.h>
using namespace std;
long long a[200010],s[200010],l[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	int n;
	cin>>n;
	l[1]=1;
	long long ans=0;
	for(int i=1;i<=n;i++){
		char ar;
		cin>>a[i]>>ar;
		s[i]=int(ar-'a');
		l[i+1]=l[i]+a[i];
	}
	long long m=l[n+1]-1;
	//cout<<m<<endl;
	for(long long i=1,j=m,k=1,q=n;i<j,k<q;){
		long long mi=min(l[k+1]-i,j-l[q]+1);
		if(s[k]!=s[q]){
			ans+=mi;
			//cout<<s[k]<<' '<<s[q]<<endl;
		}
		i=i+mi,j=j-mi;
		if(l[k+1]-i>j-l[q]+1){
			q=q-1;
		}
		else if(l[k+1]-i<j-l[q]+1){
			k=k+1;
		}
		else q=q-1,k=k+1;
	}
	cout<<ans;
	return 0;
}
