#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int a[N];
map<int,int>mp;
map<int,int>mp1;
vector<int>b;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			b.clear();
			mp.clear();			
			b.push_back(a[j]);
			mp[a[j]]++;	
			if(mp[a[j]]>1){
				for(int k=0;k<=j;k++){
					if(b[k]==a[j]) b.erase(b.begin()+k,b.end()-1);
				}
				mp[a[j]]=1;
			}
			b.push_back(a[j-1]);		
		}			
		for(int k=0;k<int(b.size());k++){
				mp1[b[k]]++;
		}				
	}
	for(int i=1;i<=m;i++){
		cout<<mp1[i]<<" ";
	}
	
	
	return 0;
}
