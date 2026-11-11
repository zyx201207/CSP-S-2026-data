#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	char o;
    long long sum=0;
	string s;
	int n=0;
	cin>>n;
	long long num=0;
	long long size=-1;
	for(int i=1;i<=n;i++){
		cin>>num;
		size+=num;
		cin>>o;
		for(long long j=1;j<=num;j++){
			s+=o;
		}
	}
	long long siz=size/2;
	for(long long i=0;i<=siz;i++){
		if(s[i]==s[size-i]){
			continue;
		}else{
			s[size-i]=s[i];
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
