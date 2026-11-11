#include <bits/stdc++.h>
using namespace std;

bool is_in(int s[],int g,int size){
	for (int i=0;i<size;i++){
		if(s[i]==g){
			return true;
		}
	}
	return false;
}
int where_in(int s[],int g,int size){
	for (int i=0;i<size;i++){
		if(s[i]==g){
			return i;
		}
	}
	return -1;
}

int main(){
	freopen("card.in",'r',stdin);
	freopen("card.out",'w',stdout);
	int round;
	int card[200000];
	int cnt[200000];
	int n,m;
	cin>>n>>m;
	round = n-1;
	for(int l=0;l<round;l++){
		int c;
		for(int i=l;i<n;i++){
			cin>>c;
			card[i]=c;
			for(int j=i;j>0;j--){
				if(card[j-1]==c){
					card[j-1]=EOF;
					break;
				}
			}
		}
		for(int i=0;i<n;i++){
			cnt[card[i]-1]+=1;
		}
	}
	for(int i=0;i<n;i++){
		if(!(cnt[i])){
			cout<<cnt[i]<<' ';
		}
	}
	return 0;
}
