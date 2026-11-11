//GZ-J00007,裘滨溪,贵阳市第一中学
#include<bits/stdc++.h>
using namespace std;
int a[500005];
map<int,int> M;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	bool fff=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(fff && a[i]<a[i-1]){
			fff=false;
		}
	}
	if(fff){
		for(int i=1;i<=n;i++){
			M[a[i]]=i;
		}
		for(int i=1;i<=m;i++){
			cout<<M[i]<<" ";
		}
		return 0;
	}
	if(n<=500){
		M.clear();
		for(int i=1;i<=n;i++){
			vector<int> Val;
			for(int j=i;j<=n;j++){
				bool fff=true;
				for(int k=0;k<Val.size();k++){
					if(Val[k]==a[j]){
						for(int l=k;l<Val.size();l++){
							Val.pop_back();
						}
						fff=false;
						break;
					}
				}
				if(fff){
					Val.push_back(a[j]);
				}
			}
			for(int j=0;j<Val.size();j++){
				M[Val[j]]++;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<M[i]<<" ";
		}
		return 0;
	}
	return 0;
}
