#include<bits/stdc++.h>
using namespace std;
int main(){
	//rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++rp++
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	vector<int> pok(500005);
	int n,m;
	cin>>n>>m;
	pok.push_back(0);
	
	for(int i=1;i<=n;i++){
		int l;
		cin>>l;
		pok.push_back(l);
	}
	for(int ll=1;ll<=n;ll++){
		vector<int> on(500005);
		on.push_back(0);
		for(int i=ll;i<=n;i++){
			int out=pok[i];
			for(int j=1;j<=on.size();j++){
				if(on[j]==out){
					for(int k=j;k<=on.size();k++){
						on.erase(on.begin()+k);
					}
				}
				on.push_back(out);
			}
		}
		int ans=0;
		for(int i=1;i<=on.size();i++){
			if(on[i]==ll){
				ans++;
			}
		}
		cout<<ans<<" ";
	}
	
	return 0;
}
