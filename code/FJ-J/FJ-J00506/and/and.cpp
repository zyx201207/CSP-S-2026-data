#include<bits/stdc++.h>
using namespace std;
long long gycn,gycm,gyca[200005],maxa,ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>gycn>>gycm;
	for(int i=1;i<=gycn;i++){
		cin>>gyca[i];
		maxa=max(maxa,gyca[i]);
	}
	ans=maxa;
	for(int i=1;i<=gycm;i++){
		for(int j=1;j<=gycn;j++){
			maxa=max(maxa,gyca[j]);
		}
		ans=ans&maxa;
		for(int j=1;j<=gycn;j++){
			if(gyca[j]==maxa){
				gyca[j]=-1;
				maxa=-1;
			}
		}
	}
	cout<<ans;
	return 0;
}
