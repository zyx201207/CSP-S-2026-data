//GZ-J00567，邱伟轩，贵阳市乌当第二中学 
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int add[n];
	int num[m+1];
	for(int i=0;i<m+1;i++)num[i]=0;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		add[i]=x;
	}
	int len=0;
	for(int i=0;i<n;i++){
		vector<int>card;
		len=0;
		for(int j=0;j<n;j++){
			if(add[j]==0)continue;
			card.push_back(add[j]);
			len++;
			int sub=-1;
			for(int a=0;a<len;a++){
				for(int b=a;b<len;b++){
					if(a==b)continue;
					if(card[a]==0||card[b]==0)continue;
					if(card[a]==card[b]){
						sub=a;
						break;
					}
				}
			}
			if(sub!=-1){
			for(int k=sub;k<len-1;k++){
				if(card[k]==0)continue;
				card[k]=0;
			}
		}
		}
		add[i]=0;
		for(int k=0;k<len;k++){
		if(card[k]!=0){
		num[card[k]]++;
		} 
	}
}
	for(int i=1;i<m+1;i++){
		cout<<num[i]<<' '; 
	}
	return 0;
}
