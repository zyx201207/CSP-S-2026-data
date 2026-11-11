#include<bits/stdc++.h>
using namespace std;
int n,l,r;
long long a[200005];
char s[200005]; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	l=1,r=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	int cnt=0;
	int c1=a[l],c2=a[r];
	while(l<r){
		if(s[l]==s[r]){
			if(c1==c2) l++,r--,c1=a[l],c2=a[r];
			else if(c1<c2) l++,c2-=c1,c1=a[l];
			else r--,c1-=c2,c2=a[r];
		}
		else{
			if(c1==c2) cnt+=c1,l++,r--,c1=a[l],c2=a[r];
			else if(c1<c2) cnt+=c1,l++,c2-=c1,c1=a[l];
			else cnt+=c2,r--,c1-=c2,c2=a[r];
		}
	}
	cout<<cnt;
	return 0;
}
