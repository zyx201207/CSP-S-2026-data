#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int q,w,e,r;
	cin>>q>>w>>e>>r;
	if(q>e||q<e){
		cout<<"0000";
	}else if(q==e&&w==e){
			cout<<"1110";
		}else if(q==e&&w>r){
				cout<<"1010";
				
			}else if(q==e&&w<r){
				cout<<"1010";
			}
		
		return 0;
}