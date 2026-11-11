#include<bits/stdc++.h>
using namespace std;
long long n,m,a,ma,e,ans;
string t[200010],qu[200020];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	e=n;
	for(int i=1;i<=n;i++){
		cin>>a;
		long long s=0;
		while(a>0) {
			t[i]=char(a%2+'0')+t[i];
			s++;
			a/=2;
		}
		ma=max(ma,s);
	}
	for(int i=1;i<=n;i++){
		while(t[i].size()!=ma) {
			t[i]="0"+t[i];
		}
	}
	for(int k=0;k<ma;k++){
		int js=0;
		for(int i=1;i<=e;i++){
			if(t[i][k]=='1') {
				js++;
				qu[js]=t[i];
			}
		}
		if(js<m) continue;
		else {
			e=js;
			for(int i=1;i<=e;i++){
				t[i]=qu[i];
			}
			ans=ans+pow(2,ma-k-1);
		}
	}
	cout<<ans;
	return 0;
}
