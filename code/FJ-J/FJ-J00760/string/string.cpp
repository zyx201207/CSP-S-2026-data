#include<bits/stdc++.h>
using namespace std;
string s;
int num[200005];
char t[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,sum=0,lcnt=0,ncnt=0,ans=0;
	char f;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i]>>t[i];
		if(t[i]!=t[i+1]){
			sum++;
		}
		ncnt+=num[i];
	}
	if(sum==1){
		cout<<ncnt/2;
		return 0;
	}
	ncnt=0;
	for(int i=1;i<=n;i++){
		ncnt+=num[i];
		for(int j=lcnt;j<ncnt;j++){
			s[j]=t[i];
		}
		lcnt=ncnt;
	}
	for(int i=0;i<ncnt/2;i++){
		if(s[i]!=s[ncnt-i-1])ans++;
	}
	cout<<ans;
	return 0;
} /*6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/

