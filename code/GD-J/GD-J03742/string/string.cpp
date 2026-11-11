#include<bits/stdc++.h>
using namespace std;
int n,x,cnt=0; 
string s,m;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>m;
		while(x--){
			s+=m;
		}
	}
	int k=s.size();
	if(k%2!=0){
		int ans=(k-1)/2;
		for(int i=1;i<=ans;i++){
			if(s[ans-i]!=s[ans+i]){
				cnt++;
			}
		}
		cout<<cnt;
		return 0;
	}else{
		int ans1=(k-1)/2;
		int ans2=ans1+1;
		for(int i=0;i<=k/2;i++){
			if(s[ans1-i]!=s[ans2+i]){
				cnt++;
			}
		}
		cout<<cnt;
		return 0; 
	}
	return 0;
} 
