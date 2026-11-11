#include<bits/stdc++.h>
using namespace std;
unsigned long long n,a,len,ans;
char c;
vector<char> v;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(unsigned long long i=0;i<n;i++){
		cin>>a>>c;
		v.push_back(c);
	}
	len=v.size();
	for(unsigned long long i=0,j=len-1;i<len/2;i++,j--){
		if(v[i]!=v[j])ans++;
	}
	cout<<ans;
    return 0;
}
