#include <bits/stdc++.h>
using namespace std;
string s1="";
int n;
const int maxn=1e5*2+5;
char b[maxn];
long long a[maxn];
long long sum;
bool chec(){
	for(int i=2;i<=n;i++){
		if(b[i]!=b[i-1]) return false;
	}
	return true;
}
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		cin>>b[i];
		for(int j=1;j<=a[i];j++){
    		s1+=b[i];
    	}
	}
	if(chec()) {
		cout<<0;
		return 0;
    }
    long long s=s1.size();
    for(int i=0;i<s/2;i++){
    	if(s1[i]!=s1[s-1-i]) sum++;
    }
    printf("%lld",sum);
	return 0;
}
