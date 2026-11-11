#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e9;
unsigned long long arr[2000005];
char a[2000005];
int num;
ll ji;
unsigned long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string s;
	int n;
	cin>>n;
	num=n;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=num;i++){
		cin>>arr[i]>>a[i];
		for(int j=ji;j<ji+arr[i];j++){
			s[j]=a[i];
		}
		ji+=arr[i];
		
	}
	
	if(ji%2==0){
		unsigned long long aa=ji/2-1;
		long long cnt=0;
		for(int i=ji-1;i>aa;i--){
			if(s[i]!=s[cnt]){
				ans++;
			}
			cnt++;
		}	
	}else{
		unsigned long long aa=ji/2-1;
		long long cnt=0;
		for(int i=ji-1;i>ji/2;i--){
			if(s[i]!=s[cnt]){
				ans++;
			}
			cnt++;
		}
	}
	cout<<ans;
	
}
