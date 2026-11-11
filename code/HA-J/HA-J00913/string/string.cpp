#include<bits/stdc++.h>
using namespace std;
long long n,ans,l=0,r=0,kl=0,kr=0;
int k[200005][2],maxx=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		char c;
		cin>>k[i][0]>>c;
		k[i][1]=(int)(c);
		maxx=max(maxx,k[i][0]);
	}
	if(maxx<=500){//85
		string s;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i][0];j++){
				s+=k[i][1];
			}
		}
		for(int i=0;(i+1)*2<=s.size();i++){//	cout<<s[i]<<"  |  |  "<<s[s.size()-i-1]<<endl;
			if(s[i]!=s[s.size()-i-1]){
				ans++;
			}
		}
	}else{//100
//		for(int i=1;i<=n;i++)
		
	}
	cout<<ans;
	return 0;
}
