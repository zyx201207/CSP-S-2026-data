#include <bits/stdc++.h>
using namespace std;
struct node{
	int nb;
	char zf;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long ans=0;
	vector<node> nodes(n);
	int i=0,j=n-1;
	for (int k=0;k<n;k++){
		cin>>nodes[k].nb>>nodes[k].zf;
	}
	while (j-i>=1){
		int& ln=nodes[i].nb;
		int& rn=nodes[j].nb;
		int mn=min(ln,rn);
		char lc=nodes[i].zf;
		char rc=nodes[j].zf;
		if (lc!=rc){
			ln-=mn;
			rn-=mn;
			ans+=mn;
			if (ln==0){
				i++;
			}
			if (rn==0){
				j--;
			}
		}else{
			nodes[i].nb-=mn;
			nodes[j].nb-=mn;
			if (nodes[i].nb==0){
				i++;
			}
			if (nodes[j].nb==0){
				j--;
			}
		}
	}
	cout<<ans<<endl;
			

		
	return 0;
} 
