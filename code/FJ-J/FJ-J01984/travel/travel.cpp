#include<bits/stdc++.h>
using namespace std;
char num[5];
char sum[5];
char ans[5];
char cnt[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>num>>sum>>ans>>cnt;
	if(num[0]==ans[0]&&ans[1]==num[1]){
		cout<<1;
	}
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(sum[0]==cnt[0]&&sum[1]==cnt[1]){
		cout<<1;
	}
	else{
		cout<<0<<0<<0;
		return 0;
	}
	if((sum[2]>='D'&&cnt[2]>='D')||(sum[2]<='C'&&cnt[2]<='C')){
		cout<<1;
	}
	else{
		cout<<0<<0;
		return 0;
	}
	if(int(sum[2])-int (cnt[2])==1||int(sum[2])-int (cnt[2])==-1){
		cout<<1;
	}
	else{
		cout<<0;
		return 0; 
	}
	return 0;
} 
