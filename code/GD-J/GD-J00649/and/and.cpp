#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10000001],b[10000001],d[10000001],x,cnt;
char c;
string s[200005];
int cmp(int v,int w){
	return v>w;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.ont","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	if(m==1){
		cout<<a[1];
		return 0;
	}
	for(int i=1;i<=n;i++){
		x=a[i];
		while(x){
			c=x%2+48;
			s[i]+=c;
			x=x/2;
		}
	}
	d[0]=1;
	for(int i=1;i<=33;i++){
		d[i]=d[i-1]*2;
	}
	for(int i=s[1].size()-1;i>=0;i--){
		cnt=0;
		for(int j=1;j<=n;j++){
			if(s[j][i]=='1') cnt++;
		}
		if(cnt>=m){
			for(int j=1;j<=n;j++){
			if(s[j][i]=='1') b[j]+=d[i];
		}
		}
	}
	sort(b+1,b+1+n,cmp);
	cnt=1;
    for(int i=2;i<=n;i++){
    	if((b[i]&b[i-1])==b[i]) cnt++;
    	else cnt=1;
    	if(cnt>=m){
    		cout<<b[i];
    		return 0;
		}
	}
}
