#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int t;
	cin>>t;
	struct node{
		int gong;
		char s;
	}P[t];
	for(int i=0;i<t;i++){
		cin>>P[i].gong>>P[i].s;
	}
	int l=0,r=t-1;
	long long cnt=0;
	for(;l<=r;){
		if(P[l].s==P[r].s){
			if(P[l].gong>P[r].gong){
				P[l].gong-=P[r].gong;
				r--;
			}
			else if(P[l].gong<P[r].gong){
				P[r].gong-=P[l].gong;
				l++;
			}
			else{
				l++,r--;
			}
		}
		else{
			if(P[l].gong>P[r].gong){
				P[l].gong-=P[r].gong;
				cnt+=P[r].gong;
				r--;
			}
			else if(P[l].gong<P[r].gong){
				P[r].gong-=P[l].gong;
				cnt+=P[l].gong;
				l++;
			}
			else{
				cnt+=P[l].gong;
				l++,r--;
			}
		}
	}
	cout<<cnt;
	return 0;
}
