#include<bits/stdc++.h>
using namespace std;
long long n,a,len,l,r,sum;
string s,cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
			cin>>a>>cnt;
			for(int i=1;i<=a;i++) s+=cnt;
			len+=a;
		}
		l=0,r=len-1;
		while(l<=r){
			if(s[l]!=s[r]) sum++;
			l++;
			r--;
	}
	cout<<sum;
	return 0;
}
