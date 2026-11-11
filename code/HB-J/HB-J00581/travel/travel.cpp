#include<bits/stdc++.h>
#define ll long long
using namespace std;

string box1,box2,seat1,seat2;
ll ans[19];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>box1>>seat1>>box2>>seat2;
	if(box1==box2){
		ans[1]=1;
		if(seat1[0]+seat1[1]==seat2[0]+seat2[1]){
			ans[2]=1;
			if((seat1[2]<'D' && seat2[2]<'D') || (seat1[2]>='D' && seat2[2]>='D')){
				ans[3]=1;
				if((seat1[2]=='A' && seat2[2]=='B') || (seat1[2]=='B' && seat2[2]=='A')) ans[4]=1;
				else if((seat1[2]=='B' && seat2[2]=='C') || (seat1[2]=='C' && seat2[2]=='B')) ans[4]=1;
				else if((seat1[2]=='D' && seat2[2]=='F') || (seat1[2]=='F' && seat2[2]=='D')) ans[4]=1;
			}
		}
	}
	for(ll i=1;i<=4;i++) cout<<ans[i];
	return 0;
}
