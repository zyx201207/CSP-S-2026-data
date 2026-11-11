#include<bits/stdc++.h>
using namespace std;

char s[10000001]={};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	long long n,step=1;
	cin>>n;
	for(long long i=1;i<=n;i++){
		long long a;
		char b;
		cin>>a>>b;
		for(long long j=step;j<step+a;j++){
			s[j]=b;
		}
		step+=a;
	}
	long long i=1,j=step-1,cnt=0;
	while(i<j){
		if(s[i]!=s[j]){
			cnt++;
		}
		i++;
		j--;
	}
	cout<<cnt;
	return 0;
}
