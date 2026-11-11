#include<bits/stdc++.h>
#define ll long long
#define x first
#define y second
#define PII pair<ll,ll>
#define pb push_back
using namespace std;
const int N=1e6+10;
const int INF=0x3f3f3f3f;
ll n,m,a[N],mx,ans,ori;
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
		if(i==1)ori=a[i];
		else ori=(ori&a[i]);
	}
	if(n<=20){
		string s="";
		for(int i=1;i<=n;i++){
			s+='0';
		}
		while(1){
			if(s[n-1]=='0')s[n-1]='1';
			else if(s[n-1]=='1')s[n-1]='2';
			for(int i=n-2;i>=0;i--){
				if(s[i+1]=='2'){
					if(s[i]=='1'){
						s[i]='2';
					}else if(s[i]=='0'){
						s[i]='1';
					}
					s[i+1]='0';
				}
			}
//			cout<<s<<endl;
			ll cnt=0;
			for(int i=0;i<n;i++){
				if(s[i]=='1'){
					cnt++;
				}
			}
			if(cnt==m){
				bool flag=0;
				ll num=0;
				for(int i=1;i<=n;i++){
					if(s[i-1]=='1'){
						if(!flag){
							num=a[i];
							flag=1;
						}else{
							num=(num&a[i]);
						}
					}
				}
				ans=max(ans,num);
			} 
			if(cnt==n)break;
		}
		cout<<ans;
		exit(0);
	}
	if(m==1){
		cout<<mx;
		exit(0);
	}
	if(m==n){
		cout<<ori;
		exit(0);
	}
	if(n<=10000&&m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,(a[i]&a[j]));
			}
		}
		cout<<ans;
		exit(0);
	}
	sort(a+1,a+n+1,cmp);
	cout<<a[m];
	return 0;
}


/*
11：01,重构T3所有代码
保佑来得及 
好吧，好像上不了300了 
*/ 

