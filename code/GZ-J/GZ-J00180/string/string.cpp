//CZ-J00180  遵义市汇川区第一小学 张馨艺
#include<bits/stdc++.h>
using namespace std;
string s1,s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    int n;
	cin>>n;
	for(int i=1;i<=n*2;i++){
		string x;
		cin>>x;
		s1+=x;
	}
	int l=s1.size();
	for(int i=l-1;i>0;i++){
		s+=s1[i];
	}
	if(s==s1){
		cout<<s;
	}
	return 0;
}
