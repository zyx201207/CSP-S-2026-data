#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
long long num[200001];
char ch[200001];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i]>>ch[i]; 
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=num[i];j++){
			if(ch[i]==ch[i-1]) continue;
			s+=ch[i];
		}	
	}
	int ans=0;
	for(int i=0,j=s.length()-1;i!=j;i++,j--){
		if(s[i]!=s[j]){
			ans++;
		}
	} 
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
