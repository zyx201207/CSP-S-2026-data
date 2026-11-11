#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> shulie(n+2);
	vector<int> cishu(m+2);
	vector<int> zhan(m+2);
	int len=0;
	vector<bool> yiru(m+2,false);
	for(int i=0;i<n;i++){
		cin>>shulie[i];
	}
	for(int i=0;i<n;i++){
		int temp=shulie[n-1-i];
		if(yiru[temp]==false){
			zhan[len++]=temp;
			yiru[temp]=true;
		}
		else{
			int i__=0;
			while(zhan[len-1-i__]!=temp){
				yiru[zhan[len-1-i__]]=false;
				i__++;
			}
			len-=(i__+1);
			zhan[len++]=temp;
		}
		for(int p=0;p<len;p++){
			cishu[zhan[p]]++;
		}
	}
	for(int i=1;i<m+1;i++){
		cout<<cishu[i]<<" ";
	}
	return 0;
} 
