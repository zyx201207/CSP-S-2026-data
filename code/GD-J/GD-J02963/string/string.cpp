#include<bits/stdc++.h> 
using namespace std;
int n;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string .out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int c;
		string a;
		cin>>c>>a;
		for(int i=1;i<=c;i++){
			s+=a;
		}
	}
	int sum=0,ll=s.size();
	for (int i=0;i<=ll;i+=2){
		if (s[i]!=s[ll-i-1]) sum++;
	}
	cout<<sum;
}
