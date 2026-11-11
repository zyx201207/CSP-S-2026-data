#include<iostream>
using namespace std;
const int N=2e5+5;
int n,a[N],sum;
char c[N];
string s=" ";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
		for(int j=1;j<=a[i];j++) s+=c[i];
	}
	int half=sum/2,cnt=0;
	for(int i=1;i<=half;i++)
		if(s[i]!=s[sum-i+1]) cnt++;
	cout<<cnt;
	return 0;
}
