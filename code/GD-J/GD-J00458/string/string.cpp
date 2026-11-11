#include<bits/stdc++.h>
using namespace std;

int n,a,cnt=0,snt=0;
char c;
char cc[100010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			cnt++;
			cc[cnt]=c;
			
		}
	}
	for(int i=0;i<cnt/2;i++){
		if(cc[i]!=cc[cnt-1]){
			snt++;
		}
	}
	cout<<snt;
	return 0;	
} 
