#include<bits/stdc++.h>
using namespace std;
int n;
struct str{
	int num;
	char zm;
}a[200007];
bool pd(){
	for(int i=0;i<n/2+1;i++){
		if(a[i].num!=a[n-i-1])return 0;	
	}
	return 1;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long sum=0;
	bool xd=1;
	for(int i=0;i<n;i++){
		cin>>a[i].num>>a[i].zm;
		sum+=a[i].num;
	}
	xd=pd();
	if(sum<=200000000){
		string s=""; 
		for(int i=0;i<n;i++){
			for(int i=0;i<a[i].num;i++){
				s+=a[i].zm;
			}
		}
		int x=s.size(),ans=0;
		for(int i=0;i<x/2+1;i++){
			if(s[i]!=s[x-i-1]){
				ans++;
			}
		}
		cout<<ans;
	}
	else if(xd){
		long long ans=0;
		for(int i=0;i<n/2+1;i++){
			if(a[i].zm!=a[n-i-1].zm){
				ans+=a[i].num; 
			}
		}
		cout<<ans;
	}
	else cout<<'0';
	
	return 0;
}
