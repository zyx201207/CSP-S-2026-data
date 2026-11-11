#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
long long ans;
vector<int>xhx;
queue<int>hx;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >>n>>m;
	for(int i=1;i<=n;i++){
		cin >>a[i];
	}
	for(int i=19;i>=0;i--){
		if(xhx.size()==m){
			break;
		}
		if(xhx.size()>m){
			for(int j=0;j<xhx.size();j++){
				if(((a[xhx[j]]>>i)&1)==true){
					hx.push(xhx[j]);
				}
			}
		}
		else{	
			for(int j=1;j<=n;j++){
				if(((a[j]>>i)&1)==true){
					hx.push(j);
				}
			}
		}
		if(hx.size()>=m){
			while(xhx.size()>0){
				xhx.pop_back();
			}
			while(!hx.empty()){
				xhx.push_back(hx.front());
				hx.pop();
			}
		}
		else{
			while(!hx.empty()){
				hx.pop();
			}
		}
	}
	ans=a[xhx[0]];
	if(xhx.size()>=m){
		for(int i=1;i<m;i++){
			ans=(ans&a[xhx[i]]);
		}
	}
	else ans=0;
	cout <<ans;
	return 0;
}
