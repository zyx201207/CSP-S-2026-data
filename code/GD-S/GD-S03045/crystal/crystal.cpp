#include<bits/stdc++.h>
using namespace std;
int a[114514],s[114514],b[114514],c[114514];
int maxx=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,ans=1,cnt=0,cal;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		if(a[i]==a[i+1]){
			cnt++;
		}
	}
	cal=(1+n)*n/2;
	if(cnt==n-1){
		cout<<n<<endl;
		return  0;
	}else if(cal==s[n]){
		cout<<m<<endl;
		return  0;
	}else{
		cout<<abs(s[n/2+1]-a[1])/2;
	}
	return  0;
} 
