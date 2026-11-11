#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[1919810];
long long tong[1919810][2];
long long ans[1919810];
int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		string s;
		long long l=i+1;
		if(a[i]==a[i+1]){
			l++;
		}else{
			s+=to_string(a[i]);
		}
		for(int j=l;j<n;j++){
			if(a[j]==a[j+1]){
				j++;
			}else{
				s+=to_string(a[j]);
			}
		} 
		for(int j=0;j<s.size();j++){
			ans[int(s[j])-'0']+=1;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
} 
