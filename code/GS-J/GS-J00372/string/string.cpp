#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,m;
	scanf("%d",&n);
	char x;
	string s1;
	long long pos=1,w=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&m);
		cin>>x;
		string s2;
		w+=m;
		for(long long i=pos;i<=w;i++){
			s1[i]=x;
		}
		pos+=m;
	}
	long long s=0;
	for(long long i=1;i<=w/2;i++){
		if(s1[i]==s1[w+1-i])
		   continue;
		else{
			s++;
		}
	}
	cout<<s;
	return 0;
}
