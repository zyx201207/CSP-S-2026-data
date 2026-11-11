#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],l,r,s;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	l=a[1],r=a[n];
	for(int i=1,j=n;i<j;){
		if(c[i]!=c[j])s+=min(l,r);
		if(l>r)l-=r,r-=r;
		else l-=l,r-=l;
		if(l==r)i++,j--,l=a[i],r=a[j];
		else if(l>r){
			while(1){
				if(l<=r)break;
				j--,r+=a[j];
			}	
		}
		else {
			while(1){
				if(l>=r)break;
				i++,l+=a[i];
			}
		}
	}
	cout<<s;
	
	return 0;
}
