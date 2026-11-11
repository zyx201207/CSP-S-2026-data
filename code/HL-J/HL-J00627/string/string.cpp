#include<bits/stdc++.h>
using namespace std;
string a,b,c;
int main(){
	freopen("string.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,s = 0;
	cin>>n;
	for(int i=0;i<n;i++){
		int m;
		cin>>m>>a;
		for(int j=0;j<m;j++){
			b += a;
		}
	}
	if(b.size()%2==0){
		for(int i=0;i<b.size()/2;i++){
			c+=b[i];
		}
		reverse(c.begin(),c.end());
		for(int i=b.size()/2;i<b.size();i++){
			if(c[i-b.size()/2]!=b[i]){
				s++;
			}
		}
	}else{
		for(int i=0;i<b.size()/2-1;i++){
			c+=b[i];
		}
		reverse(c.begin(),c.end());
		for(int i=b.size()/2+1;i<b.size();i++){
			if(c[i-(b.size()/2+1)]!=b[i]){
				s++;
			}
		}
	}
	cout<<s<<endl;

	return 0;
}
