#include<bits/stdc++.h>
using namespace std;
long long gycn,gycm,gyca[500005],ans[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>gycn>>gycm;
	for(int i=1;i<=gycn;i++){
		cin>>gyca[i];
		if(gyca[i-1]!=gyca[i]){
			ans[gyca[i-1]]++;
		}
	}
	for(int i=1;i<=gycm;i++){
		cout<<ans[i];
	}
	return 0;
}
