#include<bits/stdc++.h>
using namespace std;
typedef pair<string,int>pii;
int n,m,sum;
pii a[200010];
string check(int x){
	string s,s1;
	int k;
	while(x){
		s+=(x%2+'0');
		x/=2;
	}for(int i=s.size()-1;i>=0;i--)s1+=s[i];
	return s1;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].second;
		a[i].first=check(a[i].second);
	}
	sort(a+1,a+1+n);
	sum=a[n].second;
	for(int i=n-1;i>=m;i--){
		sum=sum&a[i].second;
	}cout<<sum;
	return 0;
} 

