//Ìï•×¶÷GZ-J00051
#include<bits/stdc++.h>
using namespace std;
long long a[200005],sum;
char c[200005];
string s2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s2+=c[i];
		}
	}
	for(int i=0;i<=s2.size()/2-1;i++){
		if(s2[i]!=s2[s2.size()-i-1]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
