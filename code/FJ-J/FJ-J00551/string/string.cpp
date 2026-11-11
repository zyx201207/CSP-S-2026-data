#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,x;
	char m;
	cin>>n;
	double s[200005];
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>x>>m;
		for(int j=1;j<=x;j++){
			s[cnt+j]=m;
		}
		cnt+=x;
	}
	int cn=(cnt-1)/2;
	int c=cnt/2;
	int sum=0;
	if(cnt%2==0){
		for(int i=1;i<=c;i++){
			if(s[i]!=s[cnt+1-i]){
				sum+=1;
			}
		}
	}else{
		for(int i=1;i<=cn;i++){
			if(s[i]!=s[cnt+1-i]){
				sum+=1;
			}
		}
	}
	cout<<sum;
	return 0;
}
