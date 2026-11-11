#include<bits/stdc++.h>
using namespace std;
int n,cnt,k,b;
string a,s;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>k;
		cin>>a;
		for(int j=1;j<=k;j++){
			s+=a;
			
		}
		
	}
	if(s.size()%2==1){
		for(int i=0;i<=s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1]){
			cnt++;	
		}
	}
	}else if(s.size()%2==0){
		for(int i=0;i<=s.size()/2-1;i++){
		if(s[i]!=s[s.size()-i-1]){
			cnt++;	
		}
	}
	}
	
	cout<<cnt;
	return 0;
}
