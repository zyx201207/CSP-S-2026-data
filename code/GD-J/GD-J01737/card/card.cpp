#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n;
	cin>>n;
	int m;
	cin>>m;
	int num[m]={0};
	vector <int> a;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		a.push_back(x);
	}
	for(int i=1;i<=n;i++){
		vector <int> c;
		c.push_back(a[i-1]);
		for(int j=i+1;j<=n+1;j++){
			bool b1=false;
			int x;
			for(int k=0;k<c.size();k++){
				if(c[k]==a[j-1]){
					b1=true;
					x=k;
				}
			}
			if(b1){
				//c.erase(x,c.size()-1-x);
				int _01=c.size();
				for(int v=x;v<_01;v++){
					//cout<<1<<endl;
					c.pop_back();
				}
				
			}
			c.push_back(a[j-1]); 
		}
		
		for(int j=0;j<c.size();j++){
			num[c[j]-1]++;
			//cout<<i<<' '<<c[j]<<endl;
		}	
	}
	for(int i=0;i<m;i++){
		cout<<num[i]<<' ';
	}
	return 0;
}
