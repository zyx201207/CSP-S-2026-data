#include<bits/stdc++.h>;
using namespace std;


int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string s,s1;
	cin>>n;
	char a;
	int m,ans=0;
	for(int i=0;i<n;i++){
		cin>>m>>a;
		for(int j=0;j<m;j++){
			s+=a;
		}
	}
	s1=s;
	for(int i=0,j=s.size()-1;i<=s.size()/2;i++,j--){
		if(s[i]!=s[j]){
			s[i]=s[j];
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
	
}