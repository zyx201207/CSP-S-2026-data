//uwu
#include <bits\stdc++.h>
using namespace std;
int n,m;
int mmu[1000000],nx[1000000],ur[1600000],kksk[1600000];
void ssqf(int msa){
	bool sks[1600000]={0};
	string opo;
	bool hyw=0;
	for(int i=msa;i<n;i++){
		hyw=0;
		if(nx[i]!=0){
			i=nx[i]-1;
			hyw=1;
		}
		if(!hyw){
//			opo+=mmu[i]+'0';
			if(sks[mmu[i]]==0){
				kksk[mmu[i]]++;
			} 
			sks[mmu[i]]=1;
		}
	}
//	cout<<"第"<<msa<<"轮:"<<opo<<endl; 
//	for(int i=0;i<=m;i++){
//		kksk[i]+=sks[i];
//	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<m+10;i++){
		ur[i]--;
	}
	for(int i=0;i<n;i++){
		cin>>mmu[i];
		if(ur[mmu[i]]!=-1){
			nx[ur[mmu[i]]]=i;
		}
		ur[mmu[i]]=i;
	}
//	for(int i=0;i<n;i++){
//		cout<<nx[i]<<' '; 
//	}
	for(int smw=0;smw<n;smw++){
		ssqf(smw);
	}
	for(int i=1;i<=m;i++){
		cout<<kksk[i]<<' ';
	}
	return 0;
}

/*
感谢苍天感谢大地P4我居然会做
QWQ
 
哎呀TLE了怎么办呢
当然是丢进垃圾桶啦
饿啊~
*/

