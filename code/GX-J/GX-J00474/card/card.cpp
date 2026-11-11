#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> a,c;
	for(int i=0;i<n;i++){
		int b;
		cin>>b;
		a.push_back(b);
	}
	for(int i=0;i<m;i++){
		c.push_back(0);
	}
	vector<int>d={};
	for(int u=0;u<n;u++){
		d={};
		for(auto nums:a){
			bool k=0;
			int y=0,h=nums;
			int p=d.size();
			for(int j=0;j<p;j++){
				if(d[j]==nums){
					k=1;
					y=j;
					break;
				}
			}
			if(k){
				d.erase(d.begin()+y,d.end());
			}
			d.push_back(h);
			/*cout<<"d:";
			for(auto num:d){
				cout<<num<<" ";
			}
			cout<<endl<<endl;*/
			
		}
		
		for(int k=1;k<=m;k++){
			for(auto num:d){
				if(num==k){
					c[k-1]+=1;
				}
				
			}
		}
		a.erase(a.begin());
		/*cout<<"a:";
		for(auto num:a){
			cout<<num<<" ";
		}
		cout<<endl<<endl<<endl;*/
	}
	for(auto num:c){
		cout<<num<<" ";
	}
	return 0;
}
