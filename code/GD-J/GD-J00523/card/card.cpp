#include <iostream>
#include <vector>
using namespace std;
int p[300018];
int b[300180];
int c[300180];
int main(){
	int n,m;
	int a;
	freopen("card1.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a;
		c[i]=a;
		p[a]+=i;
		
	}
	if(n>5000){
		for(int i=1;i<=m;i++){
			cout<<p[i]<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		vector<int> s;
		cout<<s.size();
		for(int j=i;j<=n;j++){
			for(int k=0;k<s.size();k++){
				if(s[k]==c[i]){
					while(s.size()>=k){
						s.pop_back();
					}
				}
			}
			s.push_back(c[i]);
		}
		for(int j=0;j<s.size();j++){
			b[s[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
			cout<<b[i]<<" ";
		}
	
	return 0;
}
