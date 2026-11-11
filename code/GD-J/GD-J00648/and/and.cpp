#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,a[N],m,v[N],maxx,ans;
string s[N];
void zhuan(int x){
	for(int i=0;i<31;i++) s[x]=char(((a[x]>>i)&1)+'0')+s[x];
//	cout<<s[x]<<"\n";
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) s[i]="";
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) zhuan(i);
	for(int i=0,j=30;i<=30;i++,j--){
		int k=0;
		for(int j=1;j<=n;j++) if(s[j][i]=='1' && v[j]==maxx) k++;
		if(k>=m){
			for(int j=1;j<=n;j++) if(s[j][i]=='1') v[j]++,maxx=max(maxx,v[j]);
//			cout<<i<<" ";
			ans+=(1<<j);
		}
	}
	cout<<ans;
	return 0;
}
