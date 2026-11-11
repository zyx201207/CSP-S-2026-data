#include<bits/stdc++.h>
using namespace std;
struct s{
	int id;
	char c;
};
int main(){
	std::ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	vector<s> a;
	for(int i=1;i<=n;i++){
		int ip;cin>>ip;
		char st;cin>>st;
		a.push_back({ip,st});
	}
	string str="";
	for(int i=0;i<n;i++){
		for(int j=1;j<=a[i].id;j++){
			str+=a[i].c;
		}
	}
	int sum=0;
	int shang=ceil(str.length()/2.0);
	string s1="",s2="";
	s1=str.substr(0,str.length()/2);
	s2=str.substr(shang,str.length()/2);
	reverse(s2.begin(),s2.end());
	for(int i=0;i<str.length()/2;i++){
		if(s1[i]!=s2[i]){
			sum++;
		}
	}
	cout<<sum;
}
