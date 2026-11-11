#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5,M=1e9+5;
int n,a[N];
char c[N];
string s;
bool check(int mid){
	int len=s.size();
	int left=0,right=len-1;
	int cnt=0;
	for(int i=0;i<len/2+1;i++){
		if(s[left]!=s[right])cnt++;
		left++,right--;
	}
	return cnt<=mid;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	int l=0,r=M;
	while(l<=r){
		int mid=l+(r-l)/2;
		if(check(mid))r=mid-1;
		else l=mid+1;
	}
	cout<<l;
	return 0;
} 
