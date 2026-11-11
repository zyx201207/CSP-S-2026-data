#include<bits/stdc++.h>
using namespace std;
int n;
long long a,sum;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>a>>c;
		while(a--){
			s+=c;
		}
	}
	int head=0,tail=s.size()-1;
	while(head<tail){
		if(s[head]!=s[tail]) sum++;
		head++;
		tail--;
	}
	cout<<sum;
	return 0;
}

