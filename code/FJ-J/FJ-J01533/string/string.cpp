#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N];
char c[N];
string s;
long long ans=0;
void solve(int i,int j,int lena,int lenb){
	if(i>=j)return;
	int len=min(lena,lenb);
	if(c[i]!=c[j])ans+=len;
	if(lena==len){
		solve(i+1,j,a[i+1],lenb-len);
	}
	else{
		solve(i,j-1,lena-len,a[j-1]);
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int i=1,j=n;
	solve(i,j,a[i],a[j]);
	cout<<ans<<endl;
	return 0;
}
