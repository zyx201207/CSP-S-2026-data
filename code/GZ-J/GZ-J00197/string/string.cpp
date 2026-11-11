//GZ-J00197   遵义市第四中学	代铭轩 
#include <bits/stdc++.h>
using namespace std;
const int maxn=200110;
long long a1[maxn];
string a2[maxn];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	long long n,ans=0;
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a1[i];
		cin>>a2[i];
	}
	for(int i=1,j=n;i<j;){
		int c=min(a1[i],a1[j]);
			a1[i]-=c;
			a1[j]-=c;
		if(a2[i]!=a2[j]) ans+=c;
		if(a1[i]==0){
			i++;
		}
		if(a1[j]==0){
			j--;
		}
	}
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

