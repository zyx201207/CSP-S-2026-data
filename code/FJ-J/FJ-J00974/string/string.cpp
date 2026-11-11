#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+100;
long long a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	string s;
	long long cnt;
	while(n--){
		long long x;
		cin >> x;
		cnt+=x;
		char a;
		cin >> a;
		for(int i = 1; i <= x; i++){
			s+=a;
		}
	}
	string s1, s2;
	long long sum=0;
    if(s.size()%2==1){
		s1 = s.substr(0,s.size()/2);
		s2 = s.substr(s.size()/2+1,s.size());
	}else if(s.size()%2==0){
		s1 = s.substr(0, s.size()/2);
		s2 = s.substr(s.size()/2);
	}
	reverse(s2.begin(),s2.end());
	//cout << s1 << ' ' << s2 << '\n';
	for(int i = 0; i < s1.size(); i++){
		if(s1[i]!=s2[i])sum++;
	}
	cout << sum;
	return 0;
}


