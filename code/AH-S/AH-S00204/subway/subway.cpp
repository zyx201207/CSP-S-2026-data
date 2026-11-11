#include<bits/stdc++.h>
using namespace std;
struct sub{
	int lu;
	int pot;
	int tim;
	bool yon;
}at[500002];
int w[500003],count1[500002];
int c,n,m,d,q,be,en;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>w[i];
	}	
	
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		for(int j=0;j<k;j++){
			cin>>at[j].pot>>at[j].tim;
			at[j].yon=1;
			at[j].lu=i;
			count1[at[j].pot]++;
			if(count1[at[j].pot]>d){
				at[j].yon=0;
			}
		}
	}
	long long sum=0;
	for(int i=0;i<q;i++){
		cin>>be>>en;
		int u=0;
		if(be==en){
			cout<<0<<endl;
		}
		for(int j=0;j<m;j++){
			if(at[j].pot!=be){
				continue;
			}
			int n=0;
			for(int k=0;k<m;k++){
				if(at[k].pot!=en||k==j){
					continue;
				}
				if(at[k].lu==at[j].lu){
					cout<<w[k]+w[j]+at[k].tim+at[j].tim;
					n=1;
					break;
				}
			}
			if(n){
				u=1;
				break;
			}
		}
		if(u){
			continue;
		}
	}
	return 0;
}
