#include<bits/stdc++.h>
using namespace std;
long long a,ans,c[200010];
char d[200010];
vector<char> vec;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>c[i]>>d[i];
		for(int j=1;j<=c[i];j++){
			vec.push_back(d[i]);
		}
	}
	for(int i=0;i<=floor(vec.size()/2);i++){
		if(vec[i]!=vec[vec.size()-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
