#include<bits/stdc++.h>
using namespace std;
int s[100000000];
int d[100000000];
int r[100000000];
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	int a,b;
	cin>>a>>b;
	for(int i=0;i<a;i++){
		cin>>s[i];
	}
	for(int i=0;i<a;i++){
		r[i]=s[i];
	}
	
	int k=1;
	for(k=1;k<=a;k++){
		for(int i=k;i<a;i++){
			for(int j=k;j<i;j++){
				if(s[i]==s[j]){
					for(int y=j;y<i;y++){
						s[y]=0;
					}
				}
			}
		}
		for(int o=k;o<a;o++){
			if(s[o]!=0){
				d[s[o]]++;
			}
		}
		for(int i=0;i<a;i++){
			s[i]=r[i];
		}
		
	}
	d[1]+=1;
	d[b]+=1;
	for(int i=1;i<=b;i++){
		cout<<d[i]<<' ';
	}
	 
	return 0;
} 
