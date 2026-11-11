//GZ-J00440 遵义市第四中学 杨宜炜
#include<bits/stdc++.h>
using namespace std;
int n,a[100010],sum,w;
string s;
char c;
int main(){
	freopen("string.in"."r",stdin);
	freopen("string.out"."w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c;
		for(int j=0;j<a[i];j++){
			s+=c;
		}
	}
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1]){
			sum++;
		}
	}
	cout<<sum;
}
