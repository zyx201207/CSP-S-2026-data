#include<bits/stdc++.h> 
using namespace std;
long long n,ans,d=0,d1=0,d2;
string s,c,cun,d3;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n;
	

		for(long long i=1;i<=n;i++){
			cin>>ans>>c;
			d1+=ans;
			if(d<ans){
				d=ans; 
				d2+=d; 
			}
		}
			

	cout<<d1-d2;
	
	return 0;
}
