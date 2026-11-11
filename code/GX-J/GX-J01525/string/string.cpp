#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt=0;
	cin>>n;
	vector <long long> l(10005)
	while(n!=0){
		int a;
		char b;
		cin>>a>>b;
		for(int i=0;;i++){
			l[i]=b*a;
			}
		}
		if(l.size()%2!=0){
			for(int i=l.size()/2+1;i<0;i--){
				for(int j=l.size()/2+1;j<l.size()/2+1;j++)
				if(l[i]==l[j]){
					cnt++
					}
				}
			}
			else{
				for(int i=0;i<l.size();i++){
					for(int j=l.size();j<0;j--){
						cnt++
						}
					}
				}
				cout<<cnt;
	return 0;
	}
