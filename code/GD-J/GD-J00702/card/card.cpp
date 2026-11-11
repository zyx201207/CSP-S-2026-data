#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int ypd[n]={};//原牌堆
	int js[m+1]={};//出现次数
	
	for(int i=0;i<n;i++){
		cin>>ypd[i];
	}
	
	for(int i=0;i<n;i++){
		int de[n-i+1]={};//桌面
		int ps=0;//已有牌数
		int dz[m+1]={};//每个点数对应位置 
		for(int j=i;j<n;j++){
			//插入部分 
			if(dz[ypd[j]]==0){
				ps++;
				de[ps]=ypd[j];
				dz[ypd[j]]=ps; 
			} 
			else{
				int en=ps;
				for(int z=dz[ypd[j]];z<=en;z++){
					dz[de[z]]=0;
					de[z]=0;
					ps--;
				}
				ps++;
				de[ps]=ypd[j];
				dz[ypd[j]]=ps; 
			}
			
		}
		
		for(int j=1;j<=ps;j++){
			//cout<<de[j];//
			js[de[j]]++;
		}
		//cout<<endl;//
	}
	for(int i=1;i<=m;i++)cout<<js[i]<<" ";
	
	return 0;
} 
