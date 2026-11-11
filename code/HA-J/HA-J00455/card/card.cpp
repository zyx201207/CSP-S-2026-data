#include<bits/stdc++.h>
using namespace std;
const int N=600000;
int a[N],k[N],ans[N],vis[N];
int p[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans[i]=0;
	}
	for(int g=1;g<=n;g++){
		for(int i=1;i<=m;i++){
			k[i]=p[i]=0;
			vis[i]=1;
		}
		//cout<<"now game is"<<g<<":"<<endl;
		for(int i=g;i<=n;i++){
			k[a[i]]++;
			if(k[a[i]]==2){
				//cout<<"  when i="<<i<<",happen:"<<endl;
				for(int j=p[a[i]];j<i;j++){
					//cout<<"    j="<<j<<"  ,ans[a[j]]--,k[a[j]--; they are:";
					if(vis[j]==1){
					    ans[a[j]]--;
					    k[a[j]]--;
					    vis[j]=0;
					    //cout<<ans[a[j]]<<"  "<<k[a[j]]<<"  "<<endl;
					}
					else{
						//cout<<"j is delete"<<endl;
					}
				}
				k[a[i]]=1;
			}
			p[a[i]]=i;
			ans[a[i]]++;
			vis[i]=1;
		}
		//cout<<"now ans:"<<endl;
		/*for(int i=1;i<=m;i++){
			cout<<"  "<<i<<"'s ans="<<ans[i]<<endl;
			cout<<"  "<<i<<"'s p="<<p[i]<<endl;
			cout<<"  "<<i<<"'s k="<<k[i]<<endl;
		}*/
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}