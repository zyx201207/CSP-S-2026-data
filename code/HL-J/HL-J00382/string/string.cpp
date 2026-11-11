#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdin);
	int a,num=0;
	cin>>a;
	while(a--){
		long long n;
		char c;
		cin>>n>>c;
		for(int i=1;i<=n;i++){
			s+=c;
		}
		for(int i=1;i<s.size()/2;i++)
			if(s[i]!=s[s.size()-i-1])
					num++;
		
	}
		cout<<num;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

