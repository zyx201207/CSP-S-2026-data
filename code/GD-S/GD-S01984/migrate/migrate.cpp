#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,t;
int n;
ll d;
ll a[2000005];
bool isv[2000005];
int findp(int x){
	int res=0;
	for(int i=x;i>2;i--){
		if(a[i]-a[i-1]<=d&&a[i]-a[i-2]>d)res++;
		else break;
	}
	if(res==x-2){
		if(a[2]-a[1]<=d&&a[3]-a[1]>d)res++;
	}
	//cout<<"pres:"<<res<<endl;
	return res;
}
int findn(int x){
	int res=0;
	for(int i=x;i+2<=n;i++){
		if(a[i+1]-a[i]<=d&&a[i+2]-a[i]>d)res++;
		else break;
	}
	if(res==n-x-1){
		if(a[n]-a[n-1]<=d&&a[n]-a[n-2]>d)res++;
	}
	//cout<<"nres:"<<res<<endl;
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		int cnt=0;
		for(int st=1;st<=n-3;st++){
			ll n1=a[st],n2=a[st+1],n3=a[st+2],n4=a[st+3];
			if(n3-n1<=d&&n2-n1<=d&&n4-n1>d&&n4-n2<=d){
				cnt++;
				cnt+=findp(st);
				cnt+=findn(st+3);
			}
			//cout<<st<<" "<<cnt<<endl;
		}
		cout<<cnt<<endl;
	}
	
	return 0;
}


