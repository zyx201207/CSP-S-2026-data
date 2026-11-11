#include<bits/stdc++.h>
using namespace std;
const long long M=1e9+10;
long long a[M],sum,cnt;
string op;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(long long i=1;i<=n;i++){
		string st;
		cin>>a[i]>>st;
		for(long long j=cnt;j<=a[i]+cnt-1;j++){
			op[j]+=st[1];
		}
		cnt+=a[i];
	}
	for(long long i=0;i<=(op.size()-1)/2;i++){
		if(op[i]!=op[op.size()-1-i]){
		    sum++;
		}
	}
	cout<<sum;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

