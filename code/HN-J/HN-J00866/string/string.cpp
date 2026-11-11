#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,answer,middle;
string s;
struct node{
	long long num;
	char c;
};
node a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].c;
		for(int j=1;j<=a[i].num;j++){
			s+=a[i].c;
		}
	}
	if(s.size()%2==0) middle=s.size()/2-1;
	else middle=s.size()/2;
	for(int i=0;i<middle;i++){
		if(s[i]!=s[s.size()-1-i]){
			answer++;
		}
	}
	cout<<answer<<'\n';
	return 0;
}
