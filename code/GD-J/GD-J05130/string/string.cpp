#include<bits/stdc++.h>
using namespace std;
int n;
struct op{
	int g;
	char a;
}shu[200009];
string sum;
long long ans=0;
int main(){
	freopen("string3.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>shu[i].g>>shu[i].a;
		for(int j=0;j<shu[i].g;j++){
			sum+=shu[i].a;
		}
	}
	for(int i=0;i<sum.size()/2;i++){
		int a=sum.size();
		if(sum[i]!=sum[a-i]) ans++;
	}
	if(sum.size()%2!=0) ans--;
	cout<<ans<<" "<<sum.size()/2;
	return 0;
}
