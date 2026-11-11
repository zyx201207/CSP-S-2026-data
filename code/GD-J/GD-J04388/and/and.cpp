#include<bits/stdc++.h>
using namespace std;
long long a[200010];
string str[200010];
int f[200010],si=0;
string zhuan(int s){
	string r="";
	while(s){
		r=char(s%2+'0')+r;
		s/=2;
	}
	while(r.size()<si) r='0'+r;
	return r;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	long long ans=0,ma=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(a[i],ma);
	}
	string d=zhuan(ma);
	si=d.size();
	for(int i=1;i<=n;i++) str[i]=zhuan(a[i]);
	for(int i=0;i<si;i++){
		int u=0;
		for(int j=1;j<=n;j++){
			if(f[j]!=0) continue;
			else if(str[j][i]=='0') f[j]=i+1;
			else ++u;
		}
		if(u>=m) ans+=pow(2,si-i-1);
		else{
			for(int j=1;j<=n;j++){
				if(f[j]==i+1){
					f[j]=0;
				}
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
5 3
31 3 1 15 7
*/
