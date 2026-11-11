#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	vector<int>a(n+2);
	vector<char>c(n+2);
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	long long l=1,r=n,ln=a[1],rn=a[n],cnt=0;
	while(l<r){
		if(c[l]!=c[r]){
			if(ln>=rn){
				ln-=rn;
				cnt+=rn;
				rn=0;
			}
			else{
				rn-=ln;
				cnt+=ln;
				ln=0;
			}
		}
		if(c[l]==c[r]){
			if(ln>=rn){
				ln-=rn;
				rn=0;
			}
			else{
				rn-=ln;
				ln=0;
			}
		}
		if(ln==0){
			l++;
			ln=a[l];
		}
		if(rn==0){
			r--;
			rn=a[r];
		}
	}
	cout<<cnt<<"\n";
	return 0;
}

