#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	//string S;
	vector<char>S;
	for(int i=1;i<=n;i++){
		long long a;
		cin>>a;
		char c;
		cin>>c;
		for(long long j=1;j<=a;j++){
			//S+=c;
			S.push_back(c);
		}
	}
	//cout<<S;
	long long ans=0;
	for(long long i=0;i<(S.size()-1)/2;i++){
		if(S[i]!=S[S.size()-1-i])ans++;
		//cout<<S[i];
	}
	cout<<ans;
	return 0;
}

/*
2
2 a
3 a

3
2 a
2 b
1 c

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
