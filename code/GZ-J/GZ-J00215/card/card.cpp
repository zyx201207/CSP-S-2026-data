//GZ-J00215 贵州省瓮安第二中学 卢浩宇
#include<bits/stdc++.h>
using namespace std;
vector<int>v;
int n,m,sb;
int a[500005]={-1},b[300005]={-1};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		b[i]=0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=1;k<=n;k++){
		v.clear();
		for(int i=k;i<=n;i++){
    		for(int j=0;j<(int)v.size();j++){
    			if(a[i]==v[j]){
    				while(j<(int)v.size()){
    					v.pop_back();
    				}
     			}
    			break;
    		}
    		v.push_back(a[i]);
     	}
    	for(int s=0;s<(int)v.size();s++){
	    	b[v[s]]++;
    	}
	}
	cout<<b[1];
	for(int i=2;i<=m;i++) {
		cout<<" "<<b[i];
	}
	return 0;
}
