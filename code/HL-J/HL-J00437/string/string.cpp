#include<bits/stdc++.h>
using namespace std;
int n,Max;
string ans;
struct s{
	long long len;
	char c;
}a[200005];
long long sum,mid,cmp,index,diff;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].len>>a[i].c;
		sum+=a[i].len;
		for(int j=0;j<a[i].len;j++){
			ans+=a[i].c;
		}
	}
	for(int i=0;i<sum/2;i++){
		if(ans[i]!=ans[sum-i-1]){
			diff++;
		}
	}
	cout<<diff;
	return 0;
}
