// GZ-J00122 贵阳市云岩区中天中学 朱腾予

#include<bits/stdc++.h>
using namespace std;

char ss[100000010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	long long n,l,i=0;
	cin>>n;
	while(n--){
		long long x;
		char c;
		cin>>x>>c;
		while(x--) ss[i]=c,i++;
	}
	
	long long p=0,q=i-1,sssss=0;
	while(1){
		if(p==q||p+1==q) break;
		if(ss[p]!=ss[q]) sssss+=1;
		p++,q--;
	}
	
	cout << sssss;
	
	return 0;
}
