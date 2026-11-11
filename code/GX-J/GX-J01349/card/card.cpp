#include<bits/stdc++.h>
using namespace std;
const int r=1e7+10;
int e[r],cnt[r];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	set<int>s;
	for(int i=0;i<n;i++){
	 cin>>e[i];
		}
		for(int bn=0;bn<m;bn++){
			int asd[r];
			for(int g=0;g<n;g++){
				asd[g]=e[g];
				}
	for(int te=0;te<n;te++){
		if(s.find(e[te])!=string::nops){
			for(int ds=te;ds>=0;ds--){
				asd[ds]=-1;
				}
			}
			s.insert(e[te]);
			for(int i=0;i<n;i++){
				if(e[i]==bn){
					cnt[bn-1]++;
					}
				}
		}
	}
	for(int rj=0;rj<m;rj++){
		cout<<cnt[rj]<<" ";
		}
	return 0;
	}
//zako~zako~zako~
