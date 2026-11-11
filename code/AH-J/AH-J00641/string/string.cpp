#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,m,cnt=0,ans=0;
    string c,s;
    cin>>n;
    for(int i=1;i<=n;i++){
		cin>>m>>c;
		for(int j=1;j<=m;j++){
			s+=c;
		}
		ans+=m;
	}
	n=ans;
	ans/=2;
	string x,y;
	for(int i=0;i<ans;i++){
		x+=s[i];
	}
	for(int i=ans+1;i<n;i++){
		y+=s[i];
	}
	cout<<x<<" "<<y<<endl;
	for(int i=0;i<ans;i++){
		if(x[i]!=y[i]){
			cnt++;
		}
	}
	cout<<cnt;
    return 0;
}
