#include<bits/tsdc++.h>
using namespace std;
int main(){
	freopen("string.in","w",stdin);
	freopen("string.out","r",stdout);
	int n,cnt=0;
	string c1;
	cin>>n>>c1;
	string S[200000];
	for(int i=1;i<n;i++){
		cin>>S[i];
}
	for(int i=1;i<n;i++){
		cout<<S[i];
	}
	if(S[i]=S[i-1]=S[i-2]){
		cnt++;
	}
	cout<<cnt;
	return 0;
}
