//I c your mother!
#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
string s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt=1,cnt1=0;
	cin>>n;
	long long sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
		for(int j=1;j<=a[i];j++){
			s[cnt]=c[i];
			cnt++;
		}
	}
	if(sum%2){
		long long between=(sum+1)/2;
		for(int i=1;i<=between;i++)
		{
			if(s[i]!=s[between+between-i]){
				cntj++;
			}
			cout<<endl;
		}
		cout<<cntj;
	}
	else {
		long long between=sum/2;
		between++;
		for(int i=1;i<=between-1;i++){
			if(s[i]!=s[between+between-i-1]){
				cntj++;
			}
		}
		cout<<cntj;
	}
	return 0;
}
