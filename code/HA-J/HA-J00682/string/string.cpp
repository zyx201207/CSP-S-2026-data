#include<bits/stdc++.h>
using namespace std;
int n,a;
long long ans;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a);
		cin>>c;
		while(a--)s+=c;
	}
	int l=s.size()/2,ll=s.size();
	for(int i=0;i<l;i++){
		if(s[i]!=s[ll-i-1])ans++;
	}
	cout<<ans;
	return 0;
}
