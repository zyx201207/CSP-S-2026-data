#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[200005];
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n,cmp);
	if(m==1) cout<<a[1];
	else if(m==2){
		int maxx=-1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					int x=a[i],y=a[j],zz=0;
					string xx,yy;
					while(x!=0){
						if(x%2==0) xx.push_back('0');
						else xx.push_back('1');
						x/=2;
					}
					while(y!=0){
						if(y%2==0) yy.push_back('0');
						else yy.push_back('1');
						y/=2;
					}
					for(int k=0;k<min(xx.size(),yy.size());k++){
						if(xx[k]=='1'&&yy[k]=='1') zz+=pow(2,k);
					}
					maxx=max(maxx,zz);
				}
			}
		}
		cout<<maxx;
	}
	else{
		string c;
		int cnt=0;
		while(a[1]!=0){
			if(a[1]%2==0) c.push_back('0');
			else c.push_back('1');
			a[1]/=2;
		}
		for(int i=2;i<=n;i++){
			int x=a[i];
			string s;
			while(x!=0){
				if(x%2==0) s.push_back('0');
				else s.push_back('1');
				x/=2;
			}
			for(int k=0;k<min(c.size(),s.size());k++){
				if(c[k]=='1'&&s[k]=='1') c[k]='1';
			}
		}
		for(int i=0;i<c.size();i++){
			if(c[i]=='1') cnt+=pow(2,i);
		}
		cout<<cnt;
	}
	return 0;
}
