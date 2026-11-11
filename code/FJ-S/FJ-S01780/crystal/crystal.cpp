#include<bits/stdc++.h>
using namespace std;
long long n,m,a,ans,s1[100000005];
int main(){
//	freopen("in","r",stdin);
//	freopen("out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
    	cin>>s1[i];
    	ans+=s1[i];
	}
	ans=ans/n;
	for(int i=0;i<n;i++){
		if(s1[i]-'0'<=ans){
			m=m-ans+s1[i]-'0';
			if(m>=0) a++;
		}
	}
	cout<<a;

}
