#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,m=0;
	cin>>n;
	string s,s1,s2;
	int j;
	for(int i=1;i<=n;i++){
		cin>>j>>s;
		for(int x=1;x<=j;x++){
			s1+=s;
		}

	}for(int i=n;i>=1;i--){
		s2[i]=s1[n+1-i];
	}for(int i=1;i<=n;i++){
		if(s1[i]==s2[i]){
			m++;
		}else{
			continue;
		}
	}if(m==n){
		cout<<"0";
	}
	cout<<n-m;
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
