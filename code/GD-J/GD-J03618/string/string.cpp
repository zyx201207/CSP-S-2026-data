#include<bits/stdc++.h>
using namespace std;
//Trick||Treat!
string s;
long long n;
long long cnt=0;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	for(long long i=1;i<=n;i++){
		long long a;
		string q;
		cin >> a >> q;
		
		for(long long j=1;j<=a;j++){
			s+=q;
		}
	}

	
	
	long long i=0;
	long long j=s.size()-1;
	while(i<=j){

		if(s[i]!=s[j]){
			cnt++;
		}
		
		i++;
		j--;
	}
	
	
	cout << cnt;
	
	

	
	
	return 0;
}
