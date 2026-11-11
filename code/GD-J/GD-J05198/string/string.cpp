#include<bits/stdc++.h>
using namespace std;
long long l,m=0;
long long a[200010];
char b[200010];
string s;
int main(void){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>l;
	for(int i=1;i<=l;i++){
		cin>>a[i]>>b[i];
		for(int t=1;t<=a[i];t++){
			s=s+b[i];
		}
	}for(int i=0;i<=s.size()/2-1;i++){
		if(s[i]!=s[s.size()-1-i]){
			m++;
		}
	}cout<<m;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
