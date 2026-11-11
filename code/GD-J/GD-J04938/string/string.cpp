#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
long long ans,mid;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		ans+=a[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	if(n==1){
		cout<<"0";
		return 0;
	}
	long long ans2=0;
	for(int j=0;j<=ceil(ans/2);j++){
		if(s[j]!=s[ans-(j+1)]) ans2++;
	}
	cout<<ans2;
	return 0;
} 
