#include<bits/stdc++.h> 
using namespace std;
int mx(int a,int b){
	if(a>b) return a;
	return b;
}
long long a1[200005],a2[200005],cnt=0;
char s1[200005],s2[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a1[i]>>s1[i];
		a2[i]=a1[i],s2[i]=s1[i];
	}
	for(int i=0;i<=n;i++){
		for(int j=n;j>=0;j--){
			if(s1[i]!=s2[j]){
				cnt+=a1[i]-mx(a1[i]-a2[j],0);
			}
			a1[i]=mx(a1[i]-a2[j],0);
			a2[j]=mx(a2[j]-a1[i],0);
		}
	}
	
	cout<<cnt;
	return 0;
}
