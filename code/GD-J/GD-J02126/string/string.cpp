#include<bits/stdc++.h>
long long n,len,ans;
std::string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for (int i=0;i<n;i++){
		long long a;
		std::string c;
		scanf("%lld",&a);
		std::cin>>c;
		len+=a;
		for (int i=0;i<a;i++) s+=c;
	}
	len--;
	bool iS=true;
	for(int i=0;i<len/2;i++){
		if (s[i]!=s[len-i]) iS=false;
	}
//	std::cout<<iS;
	if(iS) printf("%d",0);
//	printf("%d",len);
//	std::cout<<s;
	else {
		for (int i=0;i<len/2;i++){
			if(s[i]!=s[len-i]) ans++;
		}
	}
	printf("%lld",ans);
	return 0;
}
