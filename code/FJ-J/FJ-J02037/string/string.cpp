#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+10;
int n,a[MAXN];
long long ans=0,vis=0;
char s[MAXN];
string ss="";
string sss1="",sss2="";
void judge(string x){
	int l=0,r=x.size()-1;
	while(l<r){
		if(l>=r) break;
		if(x[l]==x[r]){
			l++;r--;
			continue;
		}
		else{
			sss1+=x[l];
			sss2+=x[r];
			l++;
			r--;
			ans++;
		}
	} 
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		for(int j=1;j<=a[i];j++) ss+=s[i];
	} 
	judge(ss);
	cout<<ans;
	return 0;
}
