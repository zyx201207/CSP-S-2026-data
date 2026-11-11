#include<bits/stdc++.h>
using namespace std;
long long a,b,s[500005],o[500005],f,ans=1;
bool g=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>s[i];
		if(i==2)    f=s[i]-s[i-1];
		else if(i>=2){
			if(s[i]-s[i-1]!=f)    g=1;
		}
	}
	sort(s+1,s+a+1);
	for(int i=1;i<=a;i++)	o[i]=o[i-1]+s[i];
	if(g==0)    cout<<min(b/f+1,a);
	else{
		for(int i=1;i<=a;i++){
			for(int j=1;j<=i-ans;j++){
				if(s[i]*(i-j)-o[i-1]+o[j-1]<=b){
					ans=max(ans,(long long)(i-j+1));
				}
			}
		}
		cout<<ans;
	}
	return 0;
}

