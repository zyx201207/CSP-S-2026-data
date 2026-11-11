#include<bits/stdc++.h>
using namespace std;
long long n,ans,s,vis=1,vis2,num;
char a;
string s1;
long long a1[100001],a2[100001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>s>>a;
		num+=s;
		if(a!=s1[i-1]&&s1[i-1]!=0){
			a1[vis]=i;
			vis++;
		}
		a2[i]=s;
		s1[i]=a;
	}
	if(a1[1]==0){
		cout<<0;
		return 0;
	}
	if(s1[a1[3]]==s1[1]&&a2[a1[3]]==a2[1]){
		cout<<0;
		return 0;
	}
	if(s1[a1[3]]!=s1[1]&&a2[a1[3]]==a2[1]){
		ans+=a2[a1[3]];
	}
	else if(s1[a1[3]]!=s1[1]&&a2[a1[3]]>a2[1]){
		ans+=a2[a1[3]]-a2[1];
	}
	else if(s1[a1[3]]!=s1[1]&&a2[a1[3]]<a2[1]){
		ans+=a2[1]-a2[a1[3]];
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
