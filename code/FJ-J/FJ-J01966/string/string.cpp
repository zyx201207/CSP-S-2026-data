#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
string a;
int s;
int sum;
string aa;
int res;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	aa=aa+" ";
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		cin>>a;
		sum+=s;
		for(int j=1;j<=s;j++){
			aa=aa+a;
		}
	}
//	for(int i=1;i<=sum;i++){
//		cout<<aa[i];
//	}
	int sss=sum/2;
	for(int i=1;i<=sss;i++){
		if(aa[i]!=aa[sum-i+1]){
			res++;
		}
	}
	cout<<res;
	return 0;
}

