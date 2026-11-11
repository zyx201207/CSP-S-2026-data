#include <bits/stdc++.h>
#include <vector>
using namespace std;
long long n;
vector<char> vec;
int ans=0,num;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int j=0;j<a;j++){
			vec.push_back(c);
		}
	}
	if(vec.size()%2==0){
		num=vec.size()/2;
	}else{
		num=vec.size()/2+1;
	}
	for(int i=1;i<=num;i++){
		if(vec[i]!=vec.front()){
			ans++;
		}
		vec.pop_back();
	}
	cout<<ans;
	return 0;
}
