#include <bits/stdc++.h>
using namespace std;
long long l,r,l1,r1,n,m,cnt,a[200005];
string s,s1;
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >>  n;
	r=n-1;
	for(int i=0;i<n;i++){
		cin >> a[i]>>s1;
		s+=s1;
		
	}
	l1=a[0];
	r1=a[n-1];
	while(l<r){
		if(s[l]==s[r]){
			m=min(l1,r1);
			l1-=m;
			r1-=m;
		}
		else if(s[l]!=s[r]){
			m=min(l1,r1);
			l1-=m;
			r1-=m;
			cnt+=m;
		}
		if(l1==0){
			l+=1;
			l1=a[l];
		}
		if(r1==0){
			r-=1;
			r1=a[r];
		}
	}
	cout << cnt;
	
	return 0;
}
