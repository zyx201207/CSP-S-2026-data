#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[200005];

ll yys(ll a,ll b){
	string aa="",bb="";
	while(a!=0){
		aa=aa+char(a%2+'0');
		a/=2;
	}
	while(b!=0){
		bb=bb+char(b%2+'0');
		b/=2;
	}
	
	ll ans=0;
	
	for(int i=0;i<min(int(aa.size()),int(bb.size()));i++){
		if(aa[i]==bb[i] && aa[i]=='1'){
			ans+=pow(2,i);
		}
	}
	
	return ans;
}

bool checkB(){
	for(int i=0;i<n;i++){
		if(a[i]!=i-1){
			return 0;
		}
	}
	return 1;
}

void runningA(){
	ll ans=0;
	ans=a[0];
	for(int i=1;i<n;i++){
		ans=yys(a[i],ans);
	}
	cout<<ans;
	return ;
}

void runningB(){
	ll ans=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			ans=max(ans,yys(a[i],a[j]));
		}
	}
	
	cout<<ans;
	return ;
}

void runningC(){
	ll ans=0;
	ans=a[n-1];
	for(int i=n-2;i>=n-m;i++){
		ans=yys(ans,a[i]);
	}
	
	cout<<ans;
	return ;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	sort(a,a+n);
	
	if(m==1){
		cout<<a[n-1];
	}else if(m==n){
		runningA();
	}else if(m<=2){
		runningB();
	}else if(checkB()){
		runningC();
	}else{
		cout<<a[n-m-1];
	}
	
	return 0;
}
