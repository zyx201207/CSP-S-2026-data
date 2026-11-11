#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,M=1e6+10;
long long n,len,ans;
int a[N],lett[30];
char c[N],cc[M];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=len+1;j<=len+a[i];j++) cc[j]=c[i];
		len+=a[i];
		lett[c[i]-96]++;
	}
	int cnt=0;
	for(int i=1;i<=26;i++){
		if(lett[i]>0) cnt++;
		if(cnt>=2) break;
	}
	if(cnt==1){
		printf("0\n");
		return 0;
	}
	
	for(int i=1;i<=len/2;i++){
		if(cc[i]!=cc[len+1-i]) ans++;
	}
	printf("%lld\n",ans);
	return 0;
}
