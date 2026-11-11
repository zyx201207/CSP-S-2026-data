#include<bits/stdc++.h>
using namespace std;
char s[1000000010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	
	long long cnt=0,a=0;
	for(int i = 0;i<n;++i){
		char c;
		int b;
		cin>>b;
		cin>>c;
		
		for(int j = 0;j<b;++j){
			if(cnt+j>=1000000010){
				a=b;
				break;
			}
			s[cnt+j]=c;
		}
		if(a)break;
		cnt+=b;
	}
	if(!a){
		for(int i = 0;i<cnt/2;++i){
		if(s[cnt-i-1]!=s[i])++a;
		}
	} 
	
	cout<<a;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
