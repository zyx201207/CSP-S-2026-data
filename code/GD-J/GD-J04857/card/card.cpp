#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[500005],e[300005]={0};
	int m[300005]={0},m0[300005]={0},c[500005]={0};//zuobiao,jishu
	int z=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(m0[a[i]]>0){
			c[i]--;
			c[m[a[i]]]++;
			for(int j=m[a[i]];j<=i;j++){
				m0[a[i]]--;
			}
		}
		m[a[i]]=i;
		m0[a[i]]++;
		
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			//m[a[j]]--;
			if(c[j]>1){
				int r=c[j+1];
				while(c[r]>=0){
					r++;
				}
				c[r]++;
			}
			
		}//tiaozheng
		for(int j=i;j<n;j++){
			if(c[j]!=0){
				z+=c[j];
			}
			if(z==0){
				m0[a[j]]++;
			}
			
		}
		
	}
	for(int i=0;i<m;i++){
		cout<<m0[i];
	}
	return 0;
} 
