#include<bits/stdc++.h>
using namespace std;

const int N=2e5+10,M=1e9+10;

long long n,a[N],cnt=0;
char c[N],S[M];
long long sum=0,ans=0;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
		int t=a[i];
		while(t){
			t--;
			cnt++;
			S[cnt]=c[i];
		}
	}
	if(cnt%2==0){
		long long l=cnt/2,r=l+1;
		while(l){
			if(S[l]!=S[r])ans++;
			l--;
			r++;
		}
	}else{
		long long l=(cnt+1)/2,r=l;
		while(l){
			if(S[l]!=S[r])ans++;
			l--;
			r++;
		}
	}
	cout<<ans;
	return 0;
}
