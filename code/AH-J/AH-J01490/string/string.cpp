#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int repeattimes,locallyrepeattimes;
	int fixtimes=0;
	string repeatstring,fusionstring="";
	cin>>repeattimes;
	for(int i=0;i<repeattimes;i++){
		cin>>locallyrepeattimes;
		cin>>repeatstring;
		for(int j=0;i<locallyrepeattimes;j++){
			fusionstring+=repeatstring;
		}
	}
	for(int i=0;i<fusionstring.size()/2,i++){
		if(fusionstring[i]==fusionstring[(fusionstring.size()-1)-i]) continue;
		else fixtimes++;
	}
	cout<<fixtimes;
}