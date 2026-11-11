#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int right=1,n,m;
	cin>>n>>m;
	vector <long long> l(1005);
	for (int i=0;i<n;i++){
		cin>>l[i];
		}
		for(int i=1;i<m;i++){
			if(l[i]==m){
				l.pop();
				}
			}
			for(int i=0;i<n;i++){
				cout<<l[i];
				}
	return 0;
	}
