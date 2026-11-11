#include <bits\stdc++.h>
using namespace std;

int n;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n; 
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int i=1;i<=a;i++){
			s+=c;
		}
	}
	int l=1,r=n;
	int mid=(l+r)/2;
	int cnt =0; 
	while(l<mid){
		if(s[l]!= s[r]){
			cnt++;
			l++;
			r--;
		}
	}
	cout<<cnt;
	return 0;
}
