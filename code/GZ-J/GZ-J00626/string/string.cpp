//GZ-J00626 ÙFê–ÊÐÓ^É½ºþ…^ÆÕÈðŒWÐ£ ‡À¾¸‚Ü
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;long long l=0,sum=0,sum1=0;
	int n,a[200005];cin>>n;string c,d;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		l+=a[i];
		for(int j=1;j<=a[i];j++)
			s+=c[i];
	}
	for(long long i=0;i<=l/2;i++){
		if(s[i]!=s[l-1-i])
			sum++;
		if(s[l-1-i]!=s[i])
			sum1++;
	}
	cout<<min(sum,sum1);
	return 0;
} 
