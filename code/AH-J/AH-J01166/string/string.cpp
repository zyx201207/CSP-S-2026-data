#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL n,ans;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin>>n;
	long long t=0;
	while(n--){
		LL x;
		char c;
		cin>>x>>c;
		for(LL i=t;i<t+x;i++){
			s[i]=c;
		}
		t+=x;
	}
	string f;
	for(LL i=0;i<t;i++){
		f[t-i-1]=s[i];
	}
	bool h=0;
	for(LL i=1;i<t;i++){
		if(f[i]!=s[i]){
			h=1;
		}
	}
	if(h==0){
		cout<<0;
		return 0;
	}
	if(t%2==0){
		LL r=t/2;
		string u,v;
		for(int i=0;i<r;i++){
			u[i]=s[i];
		}
		for(int i=r;i<t;i++){
			v[i-r]=s[i];
		}
		for(int i=0;i<r;i++){
			if(u[i]!=v[i]){
				ans++;
			}
		}
	}else{
		LL r=(t-1)/2;
		string u,v;
		for(int i=0;i<r;i++){
			u[i]=s[i];
		}
		for(int i=r+1;i<t;i++){
			v[i-r-1]=s[i];
		}
		for(int i=0;i<r;i++){
			if(u[i]!=v[i]){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}

