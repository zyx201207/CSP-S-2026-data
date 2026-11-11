#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[200005];
char c[200005];
long long s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin >> n;
	long long ans = 0;
	s[0]=0;
	for(int i = 1;i<=n;i++){
		cin >> a[i] >> c[i];
		s[i]=s[i-1]+a[i];
	}
	long long ind = 0,jnd = s[n]+1,i=0,j=n,jnd2=s[n]+1;
	while(1){
		ind+=a[++i];
		int na = a[i];
		if((ind-a[i]+1)==jnd){
			break;
		}
		else if(ind>=(jnd-a[i])){
			if(c[i]==c[j])break;
			int ii = 0,jj=jnd-(ind-a[i]),kk=a[i];
			ans+=(jj-kk-1);
			break;
		}
		if(s[j]!=jnd-1){
			if((a[j]-(s[j]-jnd+1))>a[i]){
				if(c[j]!=c[i]){
					ans+=a[i];
				}jnd-=a[i];
				continue;
			}else if((a[j]-(s[j]-jnd+1))<=a[i]){
				na-=(a[j]-(s[j]-jnd+1));
				if(c[j]!=c[i]){
					ans+=(a[j]-(s[j]-jnd+1));
				}jnd-=(a[j]-(s[j]-jnd+1));
				j--;
			}
		}
		while(na-a[j]>0){
			na-=a[j];
			if(c[i]!=c[j]){
				ans+=a[j];
			}jnd-=a[j];j--;
		}
		if(na!=0){
			if(c[j]!=c[i]){
				ans+=na;
			}jnd-=na; 
		}
	}
	cout << ans;
	return 0;
}



