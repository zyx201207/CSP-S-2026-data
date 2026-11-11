#include<bits/stdc++.h>
using namespace std;

void play(const int n,const int m,const int* cards,int* types,const int start){
	int pos[m];
	for(int i=0;i<m;i++){
		pos[i]=-1;
	} 
	int stack[n];
	int end=0;
	for(int i=start;i<n;i++){
		if(pos[cards[i]-1]!=-1){
			end=pos[cards[i]-1];
			for(int j=0;j<m;j++){
				if(pos[j]>end) pos[j]=-1;
			}
			end++;
			continue;
		}
		
		stack[end]=cards[i];
		pos[cards[i]-1]=end;
		end++;
		
	}
	for(int i=0;i<m;i++){
		if(pos[i]!=-1) types[i]++;
	}
	return; 
}

int main(){
	int n,m;
	cin>>n>>m;
	int cards[n];
	for(int i=0;i<n;i++){
		cin>>cards[i];
	}	
	int types[m];
	for(int i=0;i<m;i++){
		types[i]=0;
	}
	for(int i=0;i<n;i++){
		play(n,m,cards,types,i);
	}
	for(int i=0;i<m;i++){
		cout<<types[i]<<" ";
	}
	return 0;
}
