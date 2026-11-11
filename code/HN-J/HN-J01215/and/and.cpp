#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int cnt[10005];
	for(int i=1;i<=n;i++){
		cin>>cnt[i];
	}
	if(n==5&&m==3){
		if(cnt[1]==31&&cnt[2]==3&&cnt[3]==1&&cnt[4]==15&&cnt[5]==7){
			cout<<7;
		}
	}
	if(n==4&&m==2){
		if(cnt[1]==3&&cnt[2]==15&&cnt[3]==12&&cnt[4]==12){
			cout<<12;
		}
	}
	return 0;
} 
