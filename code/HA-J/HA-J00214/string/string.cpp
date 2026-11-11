#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int n;
	cin>>n;
	
	string s,m;
	s+=' ';
	
	for(int i=1;i<=n;i++){
		int k;
		cin>>k>>m;
		for(int j=1;j<=k;j++){
			s+=m;
		}
	}
	
	int chang=s.size()-1;
//	cout<<chang;
	long long cnt=0;
	
	if(chang%2==0){
		chang=chang/2;
		for(int i=1;i<=chang;i++){
			if(s[n-i+1]==s[i]){
				continue;
			}else{
				cnt++;
			}
		}
		cout<<cnt;
		return 0;
	}else{
		for(int i=1;i<=chang;i++){
			if(s[n-i+1]==s[i]){
				if(i==1){
					cout<<0;
				}else{
					cout<<i;
				}
				return 0;
			}
		}
	}
	
	
	return 0;
}
