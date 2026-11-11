#include<bits/stdc++.h>
using namespace std;
const long long N=1e9;
long long n,len=1,sum;
vector<long long>f;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		long long a;
		char s;
		cin>>a>>s;
		for(long long j=len;j<=len+a;++j){
			//f[j]=s-'a'+1;
			f.push_back(s-'a'+1);
		}
		len+=a;
	}
	long long i=1,j=len;
	while(i<j){
		if(f[i]!=f[j]){
			sum++;
		}
		i++;
		j--;
	}
	cout<<sum;
	return 0;
}
