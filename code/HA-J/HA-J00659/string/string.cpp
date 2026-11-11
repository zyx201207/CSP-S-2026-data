#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long l,sum,pre[N],nxt[N],a[N];
int n;
string s[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		l+=a[i];
		cin>>a[i];
		cin>>s[i-1];
	}
	for(int i=1;i<=n;i++){
		if(a[i]<=0) break;
		int tmp=n-i+1,tmp1=n-i;
		if(s[i-1]==s[tmp1]) continue;
		while(a[i]>0){
			if(a[i]>=a[tmp]){
				sum+=a[tmp];
				a[i]-=a[tmp];
				a[tmp]=0;
			}
			else{
				sum+=a[i];
				a[i]=0;
				a[tmp]-=a[i];
			}
			tmp--;
		}
	}
	cout<<sum;
	return 0;
}

