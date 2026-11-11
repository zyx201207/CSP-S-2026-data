#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=0,s[200005],s1[200005];
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdin);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	sort(s+1,s+n+1) ;
	for(int i=1;i<=n;i++){
		long long q=s[i];
		while(q){
			if(q%2==1)s1[i]++;
			q/=2;
		}
		
	}
	for(int i=1;i<=n;i++){
		cout<<s1[i]<<endl; 
	}
	return 0;
}

