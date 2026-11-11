#include<bits/stdc++.h>
using namespace std;

long long hwc(string s){
	long long r=s.size(),cnt=0;
	if(r%2!=0){
		r+1;
	}
	long long mid=r/2;
//	return mid;
	for(int i=1;i<=mid;i++){
		if(s[mid-i]!=s[mid+i]){
			cnt++;
		}
	}
	return cnt;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s="";
	int n;
	scanf("%d",&n);
	while(n--){
		int x;
		char c;
		scanf("%d %c",&x,&c);
		for(int i=1;i<=x;i++){
			s+=c;
		}
	}
//	cout<<s;
	printf("%d",hwc(s));
	
	return 0;
}
