#include <bits/stdc++.h>
using namespace std;


char String[2*(10^15)+100];

int main()
{
	freopen("string.in","r",stdin) ;
	freopen("string.out","w",stdout) ;
	long long cnt=0,n,q=1,k;
	char c;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>k>>c;
		for(long long j=1;j<=k;j++){
			String[q]=c;
			q++;
		}

	}
	for(int i=1;i<=q/2;i++){
		if(String[i]!=String[q-i]){
			cnt++;
		}

	}
	cout<<cnt;
	return 0;
}
