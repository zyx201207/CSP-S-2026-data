#include <bits/stdc++.h>
using namespace std;
int n;
long long cnt=0;
long long ans=0;
const int N=2e5+10;
struct st{
	int x;
	char y;
}a[N];
int s[N];
long long sq[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	int x;
	string y;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
		sq[a[i].y-'a'+1]+=a[i].x;
		s[a[i].y-'a'+1]++;
	}
    if(s[a[1].y-'a'+1]==n){
    	cout<<0;
    	return 0;
    }
    bool f=false;
    for(int i=1;i<=n;i++){
    	
    	ans=ans+a[i].x;
		if(s[a[i].y-'a'+1]>=(n/2)&&n%2==0&&f==false){
			f=true;
		    ans=ans-sq[a[i].y-'a'+1];
		}
		else if(s[a[i].y-'a'+1]>(n/2)&&n%2==1&&f==false){
			f=true;
		    ans=ans-sq[a[i].y-'a'+1];
    	}
    }
    if(f==true){
    	cout<<ans;
    	return 0;
	}
	ans=0;
    for(int i=1;i<=n;i++){
    	ans=ans+a[i].x;
	}
	ans=ans/2;
	cout<<ans;
	return 0;
}
