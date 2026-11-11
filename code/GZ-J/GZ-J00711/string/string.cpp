//凯里市第一初级中学 刘泓毅 GZ-J00711
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long int a,ans=0;
	scanf("%lld",&a);
	vector<char>str;
	for(int i=0;i<a;i++){
		long long int q;char w;scanf("%lld %c",&q,&w);
		for(int o=0;o<q;o++)str.push_back(w);
	}
	//for(int i=0;i<str.size();i++)cout<<str[i];
	for(int i=0;i<str.size()/2;i++){
		if(str[i]==str[str.size()-i-1])continue;
		ans++;
	}
	printf("%lld",ans);
	return 0;
}
//3
//2 a
//2 b
//1 c
