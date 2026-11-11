#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long a,b;
	cin>>a>>b;
	int c[a];
	int d[b]={};
	for(int i=0;i<a;i++){
		cin>>c[i];
	}
	for(int i=0;i<a;i++){
		vector<int> csps;
		for(int p=i;p<a;p++){
			if(csps.size()==0){
				csps.push_back(c[p]);
			}else{
				int sf=0,zb=0;
				for(int l=0;l<csps.size();l++){
					if(csps[l]==c[p]){
						sf=1;
						zb=l;
						break;
					}
				}
				if(sf==1){
					for(int l=csps.size()-1;l>=zb;l--){
						csps.erase(csps.begin()+l);
					}
					csps.push_back(c[p]);
				}else{
					csps.push_back(c[p]);
				}
			}
		}
		for(int p=0;p<csps.size();p++){
			d[csps[p]-1]++;	
		}
	}
	for(int i=0;i<b;i++){
		cout<<d[i]<<" ";
	}
	return 0;
}
