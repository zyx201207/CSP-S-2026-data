#include <bits\stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin) ;
	freopen("card.out","w",stdout) ;
	string h,s="";
	long long n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int i=1;
	}
	for(int i=0;i<n;i++){
		long long zhong=0;
		cin>>h;
		s+=h;
		for(int j=0;j<i+1;j++){
			for(int z=j;z<i+1;z++){
				if(s[j]==s[z]){
					for(int m=j;m<z;j++){
						s-=s[m];
					}
				}
			}
		}
	}
	for(int i=0;i<s.size();i++){
		s[i]++;
	}
	return 0;
}
