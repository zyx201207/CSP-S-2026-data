#include<bits/stdc++.h>
using namespace std;
long long n;
string S;
int ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		int num;
		string x,t;
		cin>>num>>t;
		for(int j=0;j<num;j++){
			x+=t;
		}
		S+=x;
	}
	int mj=S.size();
	for(int i=0;i<mj;i++){
		if(S[i]==S[mj]){
			mj--;
			continue;
		}
		else ans++;
	}
	cout<<ans/2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

