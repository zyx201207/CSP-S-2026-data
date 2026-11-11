#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and3.in","r",stdin);
	freopen("and3.out","w",stdout);
	long int n,m,m_x=0,cut=1,s=0;
	int k[10007];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>k[i];
		
	}
	for(int i=0;i<n;i++){
		for(int j=1,cut=1;j<n;j++,cut++){
			if(cut==m){
				s=k[i];
				if(s>m_x){
					m_x=s;
				}
				for(int x=j;x<=n;x++){
					s=s&k[x];
				}
				if(s>m_x){
					m_x=s;
				}
			}
		}
	}
	cout<<m_x;
	return 0;
} 
