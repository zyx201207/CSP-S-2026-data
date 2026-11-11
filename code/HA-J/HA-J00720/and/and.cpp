#include<bits/stdc++.h>
using namespace std;
long long s[1000000005],si[1000000005];
long long  n,a,i=1;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>a;
	while(n--){
		cin>>s[i];
		i++;
	}
	sort(s+1,s+1+n,greater<int>());
	for(int i=1;i<=s.size()-a;i++){
		for(int j=i;j<=a+i;j++){
			si[i]=s[j]and s[j+1] and si[i];
		}
	}
	sort(si+1;si+1+n,greater<int>());
	cout<<si[1];
	return 0;
}
