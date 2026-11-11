#include<bits/stdc++.h>
using namespace std;
freopen("card.in","r"stdin);
freopen("card.out","w"stdout);
int main(){
	int L,m;
	string S;
	cin>>L;
	int sum=0,cnt=0;
	for(int i=1;i<=L;i++){
		cin>>m;
		cin>>S[i];
		if(S[i]==S[0]){
			sum+=m;
			cnt++;
		}
		if(L<(cnt*2)){
			sum=m*L/2;
			break;
		}
		
	}
	cout<<sum;
	
	return 0;
}
