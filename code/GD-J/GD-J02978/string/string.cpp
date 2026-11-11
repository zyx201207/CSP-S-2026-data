#include<bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(nullptr);
//	ios::snyc_with_studio(false);
//	ios::snyc_with_studio(false);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,ans=0,m=0;
	string S;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			S+=c;
		}
		m+=a;
//		S+=a*c;
	}

//	cout<<S;
	for(int i=0,j=m-1;i<=S.size()/2,j>=S.size()/2;){
		if(S[i]!=S[j]){
			ans++;
//			S[j]=S[i];
//			cout<<S[i]<<" "<<S[j]<<" "<<i<<" "<<j<<endl;
		}
		i++;j--;
//		else{
//
//		}
	}
	cout<<ans;
	return 0;
}
