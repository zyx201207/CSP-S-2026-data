#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	int a[n+10];
	long long sum=0;
	string s;
	char q;
	for (int i = 1;i <= n;i++){
		cin >> a[i]>>q;	
		for(long long j = sum+1;j <= sum+a[i];j++){
			s[j]=q;
		}
		sum += a[i];
	}
	long long cnt=1,step=0;
	if(sum%2==0){
		for(long long i = sum;i >= sum/2+1;i--){
			if(s[i]!=s[cnt])
			{
				step++;
				cnt++;
			}
			else{
				cnt++;
			}
		}
	}
	else{
		for(long long i = sum;i > ceil(sum/2);i--){
			if(s[i]!=s[cnt])
			{
				step++;
				cnt++;
			}
			else{
				cnt++;
			}
		}
	}
	cout << step;
	return 0;
}
