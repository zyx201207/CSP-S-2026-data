#include <bits/stdc++.h>
using namespace std;

const int MAXN(2E5+5);
int a[MAXN];
char b[MAXN];
long long x[26];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long r(0);
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		r+=a[i];
		x[b[i]-'a']+=a[i];
	}
	long long ans=r/2;
	long long i(0);
	long long j(n);
	while(i<=j){
		if(b[i]==b[j] && i!=j){
			long long x=min(a[i],a[j]);
			ans-=x;
			a[i]-=x;
			a[j]-=x;
			if(a[i]==0){
				i++;
			}
			if(a[j]==0){
				j--;
			}
		}else if(b[i]!=b[j]){
			long long x=min(a[i],a[j]);
			a[i]-=x;
			a[j]-=x;
			if(a[i]==0){
				i++;
			}
			if(a[j]==0){
				j--;
			}
		}else{
			ans-=a[i]/2;
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}
