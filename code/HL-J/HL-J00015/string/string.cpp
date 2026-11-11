#include<bits/stdc++.h>
using namespace std;
char ch[200005];
int main(){
	freopen("string.in","r",stdin);	
	freopen("string.out","w",stdout);
	int n;
	long long sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		long long a;
		char cha;
		cin>>a>>cha;
		for(int j=1;j<=a;j++){
			ch[sum]=cha;
			sum++;
		}
	}
	int cnt=0;
	int l=0,r=sum;
	while(l<=r){
		if(ch[l]!=ch[r]){
			cnt++;
		}
		l++;
		r--;
	}
	cout<<cnt;
	return 0;
}
