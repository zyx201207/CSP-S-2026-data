#include<bits/stdc++.h>
using namespace std;

int l[500010];
int numcount[300010];
int n,m;

void fun(int startp){
	
	int l2[n+5]={};
	int numplace[m+5]={};
	for(int i=startp;i<=n;i++){
		
		int num = l[i];
		if(numplace[num] == 0){
			numplace[num] = i;
		}else{
			for(int j=numplace[num];j<i;j++){
				l2[j] = 1;
				numplace[l[j]] = 0;
			}
			numplace[num] = i;
		}
		
	}
	for(int i=startp;i<=n;i++){
		if(l2[i])continue;
		numcount[l[i]]+=1;
	}
	return;
	
}

int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>l[i];
	}
	
	for(int i=1;i<=n;i++){
		fun(i);
	}
	for(int i=1;i<=m;i++){
		cout<<numcount[i]<<" ";
	}
	cout<<"\n";
	
	
	return 0;
	
	
}
