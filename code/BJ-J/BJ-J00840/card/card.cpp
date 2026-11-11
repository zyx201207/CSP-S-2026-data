#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+2,MAXM=3e5+2;
int n,m,a[MAXN],ans[MAXM];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		vector<int> table;
		bool istable[MAXM]={};
		//cout<<"in"<<i<<"\n";
		for(int j=i;j<=n;j++){
			int x=a[j];
            //cout<<"in "<<i<<" get "<<x<<"\n";
			while(istable[x]){
                istable[table.back()]=0;
                //cout<<"I pop "<<table.back()<<"\n";
                table.pop_back();
			}
			//cout<<"push "<<x<<"\n";
			table.push_back(x);
			istable[x]=1;
		}
		//cout<<"have ";
		for(int k:table){
            ans[k]++;
            //cout<<k<<" ";
		}
		//cout<<"on table\n\n";
	}
	for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
	}
	return 0;
}
