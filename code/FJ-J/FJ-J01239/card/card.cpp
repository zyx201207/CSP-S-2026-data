#include<bits/stdc++.h>
using namespace std;

int n,m,a[500005],k,tj[300005],ti[50005],tl[300005];
vector<int> q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	//if(n<=5000&&m<=3000){
		for(int h=1;h<=n;h++){
			tj[a[h]]=1; ti[a[h]]=0;
			q.push_back(a[h]);
			for(int i=h+1;i<=n;i++){
				if(tj[a[i]]==0){
					q.push_back(a[i]);
					tj[a[i]]++; ti[a[i]]=q.size()-1;
				}
				else{
					int fi=ti[a[i]];
					for(int j=fi+1;j<q.size();j++){
						tj[q[j]]--;
					}q.erase(q.begin()+fi+1,q.begin()+q.size());
				}
			}
			for(int j=1;j<=m;j++){
				//cout<<tj[j]<<" ";
				if(tj[j]>0) tl[j]++;
			}//cout<<endl;
			q.clear(); memset(ti,0,sizeof(ti)); memset(tj,0,sizeof(tj));
		}
		for(int i=1;i<=m;i++) cout<<tl[i]<<' ';
	//}
	
}
