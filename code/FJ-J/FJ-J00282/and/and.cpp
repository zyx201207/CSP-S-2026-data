#include<bits/stdc++.h>
using namespace std;string str[200005];long long macs;
void to(long long a,long long xb){long long b;
	for(int i=1;i<a;i*=2){
		b=i;
	}
	for(int i=b;i>=1;i/=2){
		if(a>=i){
			a-=i;
			str[xb]+='1';
		}else{
			str[xb]+='0';
		}
	}
	return ;
}
void yu(string a,string b,string &ans){string k="";
	for(int i=min(a.size(),b.size())-1;i>=0;i--){
		if(a[i]==b[i]&&a[i]=='1'){
			k+='1';
		}else{
			k+='0';
		}
	}int p=0;ans="";
	for(int i=k.size()-1;i>=0;i--){
		if(k[i]=='1'){
			p=1;
		}
		if(p){
			ans+=k[i];
		}
	}
}
long long out(string a){long long ans=0;
	for(int i=0,j=1;i<a.size();i++){
		if(a[i]=='1'){
			ans+=j;
		}j*=2;
	}return ans;
}
void pd(long long m,string a){string tans="0";long long xb=0;
    
	for(int i=1;i<=m;i++){string ans="";
		yu(a,str[i],ans);
		if(out(ans)>out(tans)){
			tans=ans;
			xb=i;
		}
	}str[xb]="0";
	if(m==1){
    	cout<<out(tans);
    	return ;
	}
	pd(m-1,tans);
	
	return ;
}
long long a[200005];
int main(){
	ios::sync_with_stdio(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		macs=max(macs,a[i]);
		to(a[i],i);
	}
	
	if(m==1){
		cout<<macs;return 0;
	}
	if(m==n){string ans=str[1];
		for(int i=1;i<=n;i++){
			yu(ans,str[i],ans);
		}cout<<out(ans);return 0;
	}if(m==n-1){long long tans=-1919810;
		for(int i=1;i<n;i++){
		string ans=str[i+1];
			for(int j=1;j<=n;j++){
				if(j==i||j==i+1){
					continue;
				}
				yu(ans,str[j],ans);
			}long long q=out(ans);
			tans=max(tans,q);
		}
		string ans=str[1];
		for(int j=1;j<=n;j++){
			if(j==1||j==n){
				continue;
			}
			yu(ans,str[j],ans);
		}tans=max(tans,out(ans));
		cout<<tans;
	}
	pd(m,"11111111111111111111");
	return 0;
}
