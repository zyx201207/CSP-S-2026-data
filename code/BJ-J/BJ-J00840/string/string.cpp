#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+3;
unsigned long long n,ans=0;
pair<unsigned long long,char> chars[MAXN];
unsigned long long go(){
    ans=0;
	cin>>n;
	int mid=ceil(n/2.0);
	for(int i=1;i<=n;i++){
		cin>>chars[i].first>>chars[i].second;
	}
	for(int i=1,j=n;j>=i;){
		if(chars[i].first==0||chars[j].first==0) break;
		unsigned long long x=min(chars[i].first,chars[j].first);
        if(i!=j) chars[i].first-=x;
		chars[j].first-=x;
		if(chars[i].second!=chars[j].second) ans+=x;
		if(chars[i].first==0) i++;
		if(chars[j].first==0) j--;
	}
	return ans;
}
int main(){
	freopen("string.out","w",stdout);
	freopen("string.in","r",stdin);
	cout<<go();
	return 0;
}
