#include<iostream>
using namespace std;
long long n,ans,ze=0,cnt=0;string s;
	long long a;
	char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a>>c;
		while(a>0){
			s+=c;
			a--;
		}
		ze+=a;
	}
	long long i=0,j=ze-1;
	while(1){
		if(s[i]==s[j]){
		cnt++;
		}i++;j--;
		if(i>=j) break;
	}ans=(ze/2)-cnt;
	cout<<ans;
	return 0;
}
