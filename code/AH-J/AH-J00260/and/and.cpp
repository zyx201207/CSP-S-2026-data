#include<bits/stdc++.h>
using namespace std;
long long a[1000005],b[1000005],ans;
int t[1000005];
string s[1000005];
bool cmp(int x,int y){
	if(b[x]!=b[y])return b[x]>b[y];
	else return a[x]>a[y];
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		long long x,cnt=0;
		cin>>a[i];
		x=a[i];
		while(x!=0){
			s[i]+=(x%2+'0');
			cnt+=x%2;
			x/=2;
		}	
	}
	for(int i=1;i<=n;i++){
		t[i]=i;
	}
	sort(t+1,t+n+1,cmp);
	ans=a[t[1]];
	for(int i=2;i<=m;i++){
		ans=ans&a[t[i]];
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
