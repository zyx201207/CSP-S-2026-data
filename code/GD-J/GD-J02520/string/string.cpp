#include<bits/stdc++.h>
using namespace std;
char s[100000010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int ans=0,it=1;
	int n,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		sum+=a;
		for(int i=it;i<=sum;i++){
			s[i]=c;
		}
		it=sum+1;
	}
//	cout<<sum;
	for(int i=1;i<=sum/2;i++){
		if(s[i]!=s[sum+1-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

in:
out:
*/
