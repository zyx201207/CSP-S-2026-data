#include<bits/stdc++.h>
using namespace std;
long long n,m,num,num1;
long long n1[500009];//卡牌顺序 
long long m1[300009];//这个点这几局出现了几次 
long long m2[300009];//本局打出的牌 
long long m3[300009];//有无这张牌及牌的下标 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m; 
	for(int i=0;i<n;i++){
		cin>>n1[i];
	}for(int i=0;i<n;i++){
		//遍历n局 
		//num指本局打到第几张，所以m2的用的初始下标为1 
		for(int j=i;j<n;j++){
			//有无这张牌
			if(m3[n1[j]]==0){
				//无这张牌
				//本局打出这张牌
				//变为有这张牌，把这张牌的下标+1存入m3中 
				m2[j]=n1[j];
				m3[n1[j]]=j;
				cout<<m3[n1[j]]<<' ';
			}else{
				m2[j]=n1[j];
				m3[n1[j]]=j;
				//有这张牌
				//打到张数改变
				for(int k=m3[n1[j]];k<j;k++){
					cout<<m3[n1[j]]<<' ';
					//回收之前的牌，下标变为零即表示没有 
					m3[m2[k]]=0;
					m2[k]=0;
				}
			}
		}
		//判断剩了什么牌 
		for(int j=0;j<m;j++){
			//剩了的牌自加 
			if(m3[j]!=0){
				m1[m2[j]]+=1;
			}m3[j]=0;
			m2[j]=0;
		}
	}
	//输出剩的牌
	for(int i=1;i<=m;i++){
		cout<<m1[i]<<' ';
	} 
	return 0;
}
