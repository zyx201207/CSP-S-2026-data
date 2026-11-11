#include<bits/stdc++.h>
using namespace std;

const int N=2e5+3;
long long n,a[N],num,sum;
char c;
string s=" ";

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	//ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c;
		for(int j=1;j<=a[i];j++){
			s+=c;
		}
		sum+=a[i];
	}
	int x=s.size()/2;
	for(int i=1;i<=x;i++){
		if(i==sum-i+1){
			break;
		}
		if(s[i]!=s[sum-i+1]){
			num++;
		}
	}cout<<num;
	return 0;
}
