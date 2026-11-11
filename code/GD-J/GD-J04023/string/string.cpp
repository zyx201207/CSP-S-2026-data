#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
using namespace std;
struct Node{
	char cha;
	int numb;
	string s1;
};
vector<Node> a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	int num;
	char c;
	string s="";
	for(int i=1;i<=n;i++){
		cin>>num>>c;
		bool flag=false;
		for(int i=1;i<=a.size();i++){
			if(a[i].cha==c&&a[i].numb==num){
				s+=a[i].s1;
				flag=true;
				break;
			}
		}
		if(flag) continue;
		string s2="";
		for(int i=1;i<=num;i++){
			s2+=c;
		}
		a.push_back({c,num,s2});
		s+=s2;
	}
	int si=s.size()-1;
	long long f=0;
	for(int i=0;i<si/2;i++){
		if(s[i]!=s[si-i]){
			f++;
		}
	}
	cout<<f<<endl;
	return 0;
}
