#include<bits/stdc++.h>
using namespace std;
vector<char> s;
vector<pair<long long,char> > as;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a,n,ans=0;
	char si,jk;
	scanf("%d",&n);
	for(long long i=0;i<n;i++){
		scanf("%d",&a);
		scanf("%c",&jk);
		scanf("%c",&si);
		for(long long j=0;j<a;j++){
			s.push_back(si);
		}
	}
	for(long long i=0;i<=s.size()/2;i++){
		long long l=i,r=s.size()-i-1;
		if(s[l]!=s[r]){
			ans++;
		}
	}
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
