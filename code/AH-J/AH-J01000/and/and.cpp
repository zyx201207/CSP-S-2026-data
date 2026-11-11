#include<bits/stdc++.h>
using namespace std;
long long a,k,s1,ss;
long long com[50]={0,1};
struct st{
	int name;
	string s;
}f[200005];
string tran(long long x){
	int len=31;
	string s="";
	while(len>0){
		if(x>=com[len]){
			x-=com[len];
			s+="1";
		}else s+="0";
		len--;
	}
	return s;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long cnt=1;
	for(int i=2;i<=31;i++){
		com[i]=cnt*2;
		cnt*=2;
	}
	cin>>a>>k;
	for(int i=1;i<=a;i++){
		cin>>f[i].name;
		f[i].s=tran(f[i].name);
	}
	for(int i=0;i<31;i++){
		int cnt=0;
		for(int j=1;j<=a;j++){
			if(f[j].s=="-") continue;
			if(f[j].s[i]=='1'){
				cnt++;
			}
		}
		if(cnt>=k){
			for(int j=1;j<=a;j++) if(f[j].s[i]=='0') f[j].s="-";
			ss+=com[31-i];
		}
	}
	cout<<ss;
	return 0;
}
