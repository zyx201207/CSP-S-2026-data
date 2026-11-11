#include<bits/stdc++.h>
using namespace std;
#define int long long
struct T{
	int t;
	char c;
};
T a[200005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		cin>>a[i].t>>a[i].c;
		s+=string(a[i].t,a[i].c);
	}
	int sum=0;
	for(int i=0,j=s.size()-1;i<s.size(),j>=0,i<j;i++,j--){
		if(s[i]!=s[j]) s[j]=s[i],sum++;
	}
	/*for(int i=n,j=1;i>=1,j<=n;){
		if(a[i].c==a[j].c){
			if(a[i].t<a[j].t) a[j].t-=a[i].t,a[i].t=0,i--;
			else if(a[i].t>a[j].t) a[i].t-=a[j].t,a[j].t=0,j++;
		} 
		sum+=abs(a[i].t-a[j].t);
		if(a[i].t>a[j].t) a[i].t-=a[j].t,j++;
		else if(a[j].t>a[i].t) a[j].t-=a[i].t,i--;
		else i--,j++;
	}*/
	cout<<sum;
	return 0;
}
