#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	long long n,cntl=0,cntr=0,a[100005],ans=0;
	char s[100005];
	cin>>n;
	cntr=n-1;
	for(long long i=0;i<n;i++){
		cin>>a[i]>>s[i];
	}
	while(cntl<cntr){
		if(s[cntl]==s[cntr]){
			if(a[cntl]>a[cntr]){
				a[cntl]-=a[cntr];
				cntr--;
			}else if(a[cntl]<a[cntr]){
				a[cntr]-=a[cntl];
				cntl++;
			}else{
				cntl++;
				cntr--;
			}
		}else{
			if(a[cntl]>a[cntr]){
				a[cntl]-=a[cntr];
				ans+=a[cntr];
				cntr--;
			}else if(a[cntl]<a[cntr]){
				a[cntr]-=a[cntl];
				ans+=a[cntl];
				cntl++;
			}else{
				ans+=a[cntl];
				cntl++;
				cntr--;
			}
		}
	}
	cout<<ans;
	return 0;
}

