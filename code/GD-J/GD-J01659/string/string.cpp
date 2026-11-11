#include <bits/stdc++.h>
using namespace std;

const int MAXN=200005;

long long n,a[MAXN];
char c[MAXN];
long long aLen;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i=0;i<n;i++){
		cin >> a[i] >> c[i];
		aLen+=a[i];
	}
	
	long long len=aLen/2+(aLen%2),l=0,r=len;
	long long curr,curl=0;
	
    long long firstStep;
	long long sum=0;
	for (int i=0;i<n;i++){
		sum+=a[i];
		if(sum>=len){			
			firstStep=sum-len;
			if(sum==len) firstStep=a[i+1];
			curr=i;
		}
	}
	
	
	long long ans=0,pr,pl;;
	bool f=1;
	
	while(l<len-1 || r<aLen){
		pr=r,pl=l;
		if(r-len<l){
			long long len2;
			if(f) len2=firstStep,f=0;
			else len2=a[curr+1];
			r+=len2;
			if(c[curr]!=c[curl]){
				ans+=min(pl-pr,len2);
			}
		}
		else if(r-len>l){
			l+=a[curl+1];
			l=min(l,len-(aLen%2));
			if(c[curr]!=c[curl]){
				ans+=min(pr-pl,a[curl]);
			}
		}
		else{
			long long len2;
			if(f) len2=firstStep,f=0;
			else len2=a[curr+1];
			r+=len2;
		}
	}
	
	cout << ans;
	return 0;
}
