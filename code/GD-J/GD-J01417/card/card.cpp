#include<bits/stdc++.h>
using namespace std;
int n,m,card[int(5e5+1)],fap[int(3e5+1)];
string s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&card[i]);
		s+=char(card[i]+'0');
		if(fap[card[i]]==0){
			fap[card[i]]=i;
		}
	}
	for(int i=1;i<=n;i++){
		string s1=s;
		int fap1[m+1];
		for(int j=1;j<=m;j++){
			fap1[j]=fap[j];
		}
		for(int j=i;j<=n;j++){
			if(j>fap1[card[j]]){
				s1.delete(fap1[card[j]],i-fap1[card[i]]);
				s1+=char(card[i]+'0');
				fap1[card[i]]=j;
			}
		}cout<<s1<<endl;
	}
} 
